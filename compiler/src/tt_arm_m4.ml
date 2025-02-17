open Utils

module L = Location
module S = Syntax

(* -------------------------------------------------------------------- *)
(* ARM parsing. *)

let get_set_flags s =
  if String.ends_with s "S" then (true, String.drop_end 1 s) else (false, s)

let get_is_conditional s =
  if String.ends_with s "cc" then (true, String.drop_end 2 s) else (false, s)

let shift_kind_assoc =
  let s_of_sk sk = Conv.string_of_string0 (Arm_decl.string_of_shift_kind sk) in
  List.map (fun sk -> (s_of_sk sk, sk)) Arm_decl.shift_kinds

let get_arm_prim s =
  let is_conditional, s = get_is_conditional s in
  let set_flags, s = get_set_flags s in
  (s, set_flags, is_conditional)

let tt_prim ps s sa args =
  let name, set_flags, is_conditional = get_arm_prim s in
  match List.assoc_opt name ps with
  | Some (Sopn.PrimARM pr) ->
    if sa == S.SA
    then Some (pr set_flags is_conditional None, args)
    else None
  (* The following is for [copy], [mulu], [adc], and [sbb]. *)
  | Some (Sopn.PrimP (ws, pr)) ->
    (match sa with
     | S.SA -> Some ((pr None ws), args)
     | S.SAw ws' when ws' = ws -> Some (pr None ws, args)
     | _ -> None)
  | _ -> None
