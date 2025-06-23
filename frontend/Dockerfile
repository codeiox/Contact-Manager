# official node image 
FROM node:20-slim

# set directory inside container
WORKDIR /app

# Install pnpm globally
RUN corepack enable && corepack prepare pnpm@latest --activate

# Copy only package manager files for better cache
COPY package.json pnpm-lock.yaml ./


# Install dependencies using pnpm
RUN pnpm install

#Copy the rest of the project
COPY . .

# Expose the dev server 
EXPOSE 3000

# Start development server
CMD ["pnpm", "dev"]