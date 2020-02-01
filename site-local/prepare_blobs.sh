#!/bin/sh -e

IFDTOOL="util/ifdtool/ifdtool"
MECLEANER="util/me_cleaner/me_cleaner.py"

MEVER="11.8.70.3626_SLM_H_DA_PRD_EXTR"


cd "$(dirname $0)/.."

# Create "full" image from IFD
cp site-local/blobs/ifd.bin ifd.bin
truncate -s16M ifd.bin

# Insert ME image
${IFDTOOL} -i me:site-local/blobs/${MEVER}.bin ifd.bin
rm ifd.bin

# Extract cleaned and truncated me and adapted IFD
${MECLEANER} -t -r -d -M me.bin -D ifd.bin ifd.bin.new
rm ifd.bin.new

# Some custom IFD patching
site-local/patch_ifd.py ifd.bin

# Calculate BIOS region size
CBFSSIZE="$(printf '0x%x\n' $((0x1000000-0x1000-$(du -b me.bin | cut -f1)/0x1000*0x1000)))"
echo "CBFS size: ${CBFSSIZE}"

# Adapt config
sed -i "/^CONFIG_CBFS_SIZE/ s/=.*/=${CBFSSIZE}/" .config
