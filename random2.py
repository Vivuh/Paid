import random
import time

def random_hex_bytes(num_bytes=4000, threshold=0x80):
    # Generate random bytes and only keep those greater than the threshold
    return ''.join(f'\\x{byte:02x}' for byte in (random.randint(0, 255) for _ in range(num_bytes)) if byte > threshold)

def write_best_hex_to_file(file_name, num_bytes=4000, threshold=0x80):
    with open(file_name, 'a') as file:  # Open the file in append mode
        try:
            while True:
                random_value = random_hex_bytes(num_bytes, threshold)
                if random_value:  # Only write if the "best" bytes were found
                    file.write(random_value + '\n')
                time.sleep(0.1)  # Adjust the delay as needed
        except KeyboardInterrupt:
            print("Process stopped manually.")

# Example usage: generate unlimited "best" sequences of 100 bytes and append them to a text file
write_best_hex_to_file('best_random_hex_values.txt', num_bytes=4000, threshold=0x80)

print("Random 'best' hex values are being written to best_random_hex_values.txt. Press Ctrl+C to stop.")
