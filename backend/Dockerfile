# Stage 1: Build Drogon App
FROM debian:bookworm-slim AS builder

# 1) Install build tools & Drogon dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libjsoncpp-dev \
    libssl-dev \
    uuid-dev \
    zlib1g-dev \
    libpq-dev \
    libsqlite3-dev \
    libmysqlcppconn-dev \
    && rm -rf /var/lib/apt/lists/*

# 2) Clone and install Drogon
WORKDIR /opt
RUN git clone --recurse-submodules https://github.com/drogonframework/drogon.git \
    && cd drogon \
    && mkdir build && cd build \
    && cmake .. \
    && make -j$(nproc) \
    && make install

# 3) Copy your application source
WORKDIR /src
COPY . .

# 4) Build your Drogon application
RUN mkdir -p build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc)


# Stage 2: Runtime
FROM debian:bookworm-slim

# 5) Install only the runtime libraries
RUN apt-get update && apt-get install -y \
    libssl3 \
    libjsoncpp25 \
    libuuid1 \
    zlib1g \
    libmysqlcppconn7v5 \
    libpq5 \
    libsqlite3-0 \
    && rm -rf /var/lib/apt/lists/*

# 6) Copy the app binary from the builder
WORKDIR /app

COPY --from=builder /src/build/ContactManager .

# 7) Expose Drogon’s default port (adjust if needed)
EXPOSE 8080

# 8) Start the server
CMD ["./ContactManager"]
