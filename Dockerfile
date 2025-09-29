FROM japeto/so-tools:v64

WORKDIR /home/japeto/app
COPY . .

RUN g++ -o main main.cpp Process.cpp Simulator.cpp \
    FCFSScheduler.cpp SJFScheduler.cpp RRScheduler.cpp STCFScheduler.cpp

CMD ["./main"]
