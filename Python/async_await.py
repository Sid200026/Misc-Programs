import asyncio
import time

# the execution of a function can be paused using yield, yield_from and await.

async def test():
    await asyncio.sleep(4)
    print("Bye")

def hi():
    print("yo")

print("1")
asyncio.run(test())
hi()
print("2")

