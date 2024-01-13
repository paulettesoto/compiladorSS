# Use the official Ubuntu base image
FROM ubuntu:latest

# Update package lists and install necessary dependencies
RUN apt-get update && \
    apt-get install -y flex bison && \
    rm -rf /var/lib/apt/lists/* && \
    apt-get update && \
    apt-get install make 

# Set the working directory
WORKDIR /app/flex-bison-image

RUN apt-get update && \
    apt-get install make 

# Copy your Flex and Bison files into the container (assuming they are in the same directory as the Dockerfile)
COPY . .

# Add any other commands needed to build your project

# Specify the command to run your application (replace this with your actual command)
CMD ["/bin/bash", "-c", "./a.out compilator.txt"]

