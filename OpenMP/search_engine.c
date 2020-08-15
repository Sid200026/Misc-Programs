/*
A search engine can be implemented using a farm of servers; each contains a subset of data that can be searched. 
Assume that this farm server has a single front-end that interacts with clients who submit queries. 
Implement the above server form using master-worker pattern
*/

// Master is thread 0
// All other threads will be worker
#include <stdio.h>
#include <omp.h>

int main()
{
    int request_pool[50]; // Server can process 50 requests at any given point of time
    int response[50];
    int ip;
    int db = 4;
    int ret;
    int connection_pool = 50;
    // Db can be kept as private but with the advancements in technology and the requirements to serve data at a faster speed,
    // We many of the times use multiple snapshots of the same database to fetch results. As a result db is kept as first private
    // Initially b will point to the root database, however it may change based on the location of the IP Address.
#pragma omp parallel for private(request_pool, ip) shared(connection_pool) firstprivate(db) nowait // Do not wait for thread to complete as requests are independent of threads
    for (int i = 0; i < connection_pool; i++)
    {
        if (omp_get_thread_num() != 0) // Only workers will do the computations
        {
            int request = read_request(request_pool[i]); // Arbitrary function to read the request sent by the web-client
            ip = read_ip(request);                       // Arbitrary function to get the IP-Address
            int loc = read_location(ip);
            db = update_db_if_required(db, loc);
            int data;
#pragma omp critical
            {
                read_database(db, request);          // Read the value from the database
                data = update_database(db, request); // Update the database based on the request
                response[i] = data;
            }
        }
    }
    return response;
}