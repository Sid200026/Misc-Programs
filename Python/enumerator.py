import enum
class EnumExample(enum.Enum):
    noPerm = "Insufficient priviledges"
    notSame = "Values are not same"
    permReq = "Ask admin for permission"

class EnumTest(enum.Enum):
    hi = "Hi"

print(EnumExample.noPerm)
# EnumExample.noPerm

print(repr(EnumExample.noPerm))
# <EnumExample.noPerm: 'Insufficient priviledges'>

print(EnumExample.noPerm.name)
# noPerm

print(EnumExample.noPerm.value)
# Insufficient priviledges

# Enum cannot have two attributes with the same name

# If we want all the values to be unique
# from enum import unique
# @unique
# class .....


