# include <stdint.h>
# include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* arg: pointer to 24 × 64 bits, aligned for 64-bits memory accesses */
extern void bash(void*);

int
main(void)
{
  uint64_t input[24] = {
    0xB194BAC80A08F53B, 0x366D008E584A5DE4, 0x8504FA9D1BB6C7AC, 0x252E72C202FDCE0D,
    0x5BE3D61217B96181, 0xFE6786AD716B890B, 0x5CB0C0FF33C356B8, 0x35C405AED8E07F99,
    0xE12BDC1AE28257EC, 0x703FCCF095EE8DF1, 0xC1AB76389FE678CA, 0xF7C6F860D5BB9C4F,
    0xF33C657B637C306A, 0xDD4EA7799EB23D31, 0x3E98B56E27D3BCCF, 0x591E181F4C5AB793,
    0xE9DEE72C8F0C0FA6, 0x2DDB49F46F739647, 0x06075316ED247A37, 0x39CBA38303A98BF6,
    0x92BD9B1CE5D14101, 0x5445FBC95E4D0EF2, 0x682080AA227D642F, 0x2687F93490405511
  };

  uint64_t expected[24] = {
    0x8FE727775EA7F140, 0xB95BB6A200CBB28C, 0x7F0809C0C0BC68B7, 0xDC5AEDC841BD94E4,
    0x03630C301FC255DF, 0x5B67DB53EF65E376, 0xE8A4D797A6172F22, 0x71BA48093173D329,
    0xC3502AC946767326, 0xA2891971392D3F70, 0x89959F5D61621238, 0x655975E00E2132A0,
    0xD5018CEEDB17731C, 0xCD88FC50151D37C0, 0xD4A3359506AEDC2E, 0x6109511E7703AFBB,
    0x014642348D8568AA, 0x1A5D9868C4C7E6DF, 0xA756B1690C7C2608, 0xA2DC136F5997AB8F,
    0xBB3F4D9F033C87CA, 0x6070E117F099C409, 0x4972ACD9D976214B, 0x7CED8E3F8B6E058E
  };

  bash(input);

  for (int i = 0; i < 24; ++i) {
    printf("%s%016llx%s",
           input[i] == expected[i] ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
           input[i],
           (i & 3) < 3 ? " " : "\n");
  }
  printf("%s\n", ANSI_COLOR_RESET);

  return 0;
}
