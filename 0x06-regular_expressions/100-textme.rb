#!/usr/bin/env ruby

# Extract the relevant data using regular expressions
log_entry = ARGV[0]
from_match = log_entry.match(/\[from:(.+?)\]/)
to_match = log_entry.match(/\[to:(.+?)\]/)
flags_match = log_entry.match(/\[flags:(.+?)\]/)

# Print the extracted data in the required format
puts "#{from_match[1]},#{to_match[1]},#{flags_match[1]}"

