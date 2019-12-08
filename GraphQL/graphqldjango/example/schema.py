import graphene
from graphene_django.types import DjangoObjectType
from .models import Category, Ingredient

class CategoryType(DjangoObjectType):
    class Meta:
        model = Category

class IngredientType(DjangoObjectType):
    class Meta:
        model = Ingredient


class Query(object):
    all_categories = graphene.List(CategoryType)
    all_ingredients = graphene.List(IngredientType)
    ingredient = graphene.Field(
        IngredientType,
        name=graphene.String(),
        id=graphene.ID(),
    )
    category = graphene.Field(
        CategoryType,
        name = graphene.String(),
        id=graphene.ID(),
    )

    def resolve_all_categories(self, info, **kwargs):
        return Category.objects.all()
    
    def resolve_all_ingredients(self, info, **kwargs):
        return Ingredient.objects.all()

    def resolve_ingredient(self, info, **kwargs):
        name = kwargs.get('name')
        id = kwargs.get('id')
        if id is not None:
            return Ingredient.objects.get(pk=id)
        if name is not None:
            return Ingredient.objects.get(name=name)
        return None

    def resolve_category(self, info, **kwargs):
        name = kwargs.get('name')
        id = kwargs.get('id')
        if id is not None:
            return Category.objects.get(pk=id)
        if name is not None:
            return Category.objects.get(name=name)
        return None


class createCategoryType(graphene.Mutation):
    class Arguments: # input for mutations
        name = graphene.String()

    category = graphene.Field(CategoryType) # Response of the mutation

    def mutate(self, info, name):
        if(not Category.objects.filter(name=name).exists):
            temp = Category.objects.create(name=name)
            temp.save()
        else:
            temp = Category.objects.get(name=name)
        return createCategoryType(category=temp)

class createIngredientType(graphene.Mutation):
    class Arguments:
        id = graphene.ID()
        name = graphene.String()
        notes = graphene.String()
    
    ingredient = graphene.Field(IngredientType)

    def mutate(self, info, id, name, notes):
        category = Category.objects.get(pk=id)
        temp = Ingredient.objects.create(category=category, name=name, notes=notes)
        temp.save()

        return createIngredientType(ingredient = temp)

class Mutation(graphene.ObjectType):
    create_category = createCategoryType.Field()
    create_ingredient = createIngredientType.Field()
