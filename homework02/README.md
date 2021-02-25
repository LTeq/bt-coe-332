# bt-coe-332/homework02

The Containers and Repositories of Dr. Moreau creates a random dictionary of animals with body parts
selected from a petname library. Files include:
  
1. Dockerfile              Contains commands for installing the necessary dependencies for the program.
2. generate_animals.py     Writes a random dictionary of animals to a *.json file drawn from the petname library.
3. read_animals.py         Reads a *.json file.
4. test_read_animals.py    Runs unit tests on read_animals.py.

## Installation

Installation commands are in Dockerfile. A docker image can be built using Dockerfile through: 

docker build -t username/filename:version .

To run the scripts inside a container:

1. docker run --rm -v $PWD:/data -u $(id -u):$(id -g) <username>/<filename>:<version> generate_animals.py /data/animals.json
2. docker run --rm -v $PWD:/data <username>/<filename>:<version> read_animals.py /data/animals.json
3. docker run --rm -v $PWD:/data <username>/<filename>:<version> test_read_animals.py


Dockerfile Commands

1. FROM centos:7.7.1908
2. ENV LC_CTYPE=en_US.UTF-8
3. ENV LANG=en_US.UTF-8
4. RUN pip3 install petname==2.6

5. COPY generate_animals.py /code/generate_animals.py
6. COPY read_animals.py /code/read_animals.py
7. COPY test_read_animals.py /code/test_read_animals.py

8. RUN chmod +rx /code/generate_animals.py && chmod +rx /code/read_animals.py && chmod +rx /code/test_read_animals.py

9. ENV PATH "/code:$PATH"
