val pp_prog :
  ('reg, 'regx, 'xreg, 'rflag, 'cond, 'asm_op, 'extra_op) Arch_extra.extended_op Sopn.asmOp ->
  Format.formatter ->
  ('reg, 'regx, 'xreg, 'rflag, 'cond, 'asm_op, 'extra_op) Arch_extra.extended_op Linear.lprog ->
  unit
