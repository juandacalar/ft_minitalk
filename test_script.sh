#!/bin/bash

# Start the server in the background
./server &

# Save the PID of the server
server_pid=$!

# Wait for a moment to ensure the server is ready
sleep 1

# List of messages to test
messages=(
    "Hello, World!"
    "This is a long message that is going to test how well the server can handle large amounts of data. It should be able to handle this without any issues, as long as the client sends the data correctly."
    "This message contains special characters: @#$%^&*()"
    "This message contains a newline character.\nThis is the second line."
    "This message contains a tab character.\tThis is after the tab."
)

# Send each message to the server
for message in "${messages[@]}"; do
    ./client "$server_pid" "$message"
    sleep 1  # Wait for a moment to ensure the server has time to process the message
done

# Kill the server
kill "$server_pid"