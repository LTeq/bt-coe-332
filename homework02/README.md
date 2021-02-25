# bt-coe-332/homework02

The Containers and Repositories of Dr. Moreau creates a random dictionary of animals with body parts
selected from a petname library. Files include:
  
Dockerfile              Contains commands for installing the necessary dependencies for the program.
generate_animals.py     Writes a random dictionary of animals to a *.json file drawn from the petname library.
read_animals.py         Reads a *.json file.
test_read_animals.py    Runs unit tests on read_animals.py.

## Installation

Installation commands are in Dockerfile. A docker image can be built using Dockerfile through: 

docker build -t username/filename:version .

To run the scripts inside a container:

docker run --rm -v $PWD:/data -u $(id -u):$(id -g) <username>/<filename>:<version> generate_animals.py /data/animals.json
docker run --rm -v $PWD:/data <username>/<filename>:<version> read_animals.py /data/animals.json
docker run --rm -v $PWD:/data <username>/<filename>:<version> test_read_animals.py


Dockerfile Commands

FROM centos:7.7.1908
ENV LC_CTYPE=en_US.UTF-8
ENV LANG=en_US.UTF-8
RUN pip3 install petname==2.6

COPY generate_animals.py /code/generate_animals.py
COPY read_animals.py /code/read_animals.py
COPY test_read_animals.py /code/test_read_animals.py

RUN chmod +rx /code/generate_animals.py && chmod +rx /code/read_animals.py && chmod +rx /code/test_read_animals.py

ENV PATH "/code:$PATH"
