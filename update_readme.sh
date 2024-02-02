#!/bin/bash

# Function to count files in a folder
count_files() {
  folder="$1"
  # Check if folder exists
  if [ -d "$folder" ]; then
    count=$(find "$folder" -type f | wc -l)
    echo "$count"
  else
    echo "Folder '$folder' does not exist."
    exit 1
  fi
}

# Array of folders to count files in
folders=("Dynamic_Programming" "Geometry" "Introductory_problems" "Maths" "Range_Queries" "Searching_and_Sorting" "Trees" "Strings")

# Check if README.md exists
if [ ! -f README.md ]; then
  echo "README.md not found."
  exit 1
fi

# Initialize total count
total_count=0

# Loop through each folder, count files, and update README.md
for folder in "${folders[@]}"; do
  count=$(count_files "$folder")
  sed -i "s/\($folder :[[:space:]]*\)[0-9]*/\1$count/" README.md
  total_count=$((total_count + count))
done

# Update Total Problems count
sed -i "s/\(Total Problems solved :[[:space:]]*\)[0-9]*/\1$total_count/" README.md

# Add a new entry to the Update History
current_date_time=$(date +"%Y-%m-%d %H:%M")
echo "- Last update: $current_date_time" >> README.md

echo "README.md updated successfully."
