#!/bin/bash

# Function to count files in a folder
count_files() {
  folder="$1"
  count=$(find "$folder" -type f | wc -l)
  echo "$count"
}

# Update Dynamic Programming count
dp_count=$(count_files "Dynamic_Programming")
sed -i "s/\(Dynamic Programming :  *\)[0-9]*/\1$dp_count/" README.md

# Update Geometry count
geometry_count=$(count_files "Geometry")
sed -i "s/\(Geometry :  *\)[0-9]*/\1$geometry_count/" README.md

# Update Introductory Problems count
intro_problems_count=$(count_files "Introductory_problems")
sed -i "s/\(Introductory Problems :  *\)[0-9]*/\1$intro_problems_count/" README.md

# Update Maths count
maths_count=$(count_files "Maths")
sed -i "s/\(Maths :  *\)[0-9]*/\1$maths_count/" README.md

# Update Range Queries count
range_queries_count=$(count_files "Range_Queries")
sed -i "s/\(Range Queries :  *\)[0-9]*/\1$range_queries_count/" README.md

# Update Searching and Sorting count
search_sort_count=$(count_files "Searching_and_Sorting")
sed -i "s/\(Searching and Sorting :  *\)[0-9]*/\1$search_sort_count/" README.md

# Update Trees count
trees_count=$(count_files "Trees")
sed -i "s/\(Trees :  *\)[0-9]*/\1$trees_count/" README.md

# Update Strings count
strings_count=$(count_files "Strings")
sed -i "s/\(Strings :  *\)[0-9]*/\1$strings_count/" README.md

# Update Total Files count
total_count=$((dp_count + geometry_count + intro_problems_count + maths_count + range_queries_count + search_sort_count + trees_count + strings_count))
sed -i "s/\(Total Problems solved :  *\)[0-9]*/\1$total_count/" README.md

# Add a new entry to the Update History
current_date_time=$(date +"%Y-%m-%d %H:%M")
echo "- Last update: $current_date_time" >> README.md

echo "README.md updated successfully."
