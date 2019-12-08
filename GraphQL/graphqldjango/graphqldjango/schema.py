import graphene
import example.schema


class Query(example.schema.Query, graphene.ObjectType):
    pass
class Mutation(example.schema.Mutation, graphene.ObjectType):
    pass

schema = graphene.Schema(query=Query, mutation=Mutation, auto_camelcase=False)