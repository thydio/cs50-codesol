🖼️ Image Filter Tool

A command-line program that applies various filters to BMP images.

Features:

Grayscale conversion
Horizontal reflection
Blur effect
Edge detection (Sobel operator)

How it works:

Reads BMP headers using structs defined in
Loads pixel data into memory
Applies transformations using functions from
Writes processed image back to file

Usage:

make filter
./filter -g input.bmp output.bmp   # grayscale
./filter -r input.bmp output.bmp   # reflect
./filter -b input.bmp output.bmp   # blur
./filter -e input.bmp output.bmp   # edges

Core implementation:

🔍 Readability Analyzer

Analyzes text and outputs the reading grade level using the Coleman-Liau index.

Features:

Counts letters, words, and sentences
Computes readability score
Outputs grade level (e.g., Grade 10, Grade 16+)

Concepts Used:

String parsing
Mathematical modeling
Input handling

Usage:

make readability
./readability

Source:

💾 JPEG Recovery Tool

Recovers JPEG images from a raw memory card file.

Features:

Scans binary data in 512-byte blocks
Detects JPEG signatures
Extracts and reconstructs images

Concepts Used:

File pointers
Binary data handling
Memory allocation

Usage:

make recover
./recover card.raw

Source:

🛠️ Tech Stack
Language: C
Concepts:
Memory management
File I/O
Data structures (structs)
Image processing basics
