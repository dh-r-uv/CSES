#!/usr/bin/env bash
set -euo pipefail

README="README.md"
START="<!-- COUNTS START -->"
END="<!-- COUNTS END -->"

if [[ ! -f $README ]]; then
  echo "❌ $README not found"; exit 1
fi

# 1) Generate the new counts block in-memory
total=0
counts_block=""
for dir in */; do
  [[ -d $dir ]] || continue
  cnt=$(find "$dir" -type f | wc -l)
  total=$(( total + cnt ))
  name=$(basename "$dir" | sed 's/_/ /g')
  counts_block+="${name} : ${cnt}"$'\n'
done
counts_block+="Total Problems solved : ${total}"$'\n'

# 2) Replace the section between the markers
tmp=$(mktemp)
awk -v start="$START" -v end="$END" -v block="$counts_block" '
  $0==start { print; printf "%s", block; in_block=1; next }
  $0==end   { in_block=0 }
  !in_block { print }
  $0==end   { print; next }
' "$README" > "$tmp" && mv "$tmp" "$README"

# 3) Ensure an Update History section and append a timestamp
ts=$(date +"%Y-%m-%d %H:%M")
if ! grep -q "^## Update History" "$README"; then
  echo -e "\n## Update History" >> "$README"
fi
echo "- $ts: auto-updated counts" >> "$README"

echo "✅ README.md updated (total=${total})."
