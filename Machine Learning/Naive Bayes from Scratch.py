from math import exp, pow, pi, sqrt
dataset = [
    [4, 0, 3, 5, 1, 0, 6, 0, 'Politics'],
    [0, 5, 0, 2, 6, 0, 1, 0, 'Business'],
    [0, 0, 6, 1, 0, 4, 1, 2, 'Sports'],
    [4, 1, 0, 1, 1, 0, 6, 0, 'Politics'],
    [0, 0, 0, 0, 0, 5, 0, 6, 'Sports'],
    [0, 4, 0, 2, 6, 0, 0, 1, 'Business'],
    [5, 0, 0, 3, 0, 0, 5, 0, 'Politics'],
]

test = [[0, 3, 0, 2, 6, 0, 2, 1]]

"""
Split the train dataset into x_train and x_test
"""

CATEGORY_ENCODING = ['Politics', 'Business', 'Sports']

train = [i[0:-1] + [CATEGORY_ENCODING.index(i[-1])] for i in dataset]


"""
Utility functions
"""

# Calculate the mean of a list of numbers


def mean(numbers):
    return sum(numbers)/float(len(numbers))

# Calculate the standard deviation of a list of numbers


def std_dev(numbers):
    avg = mean(numbers)
    variance = sum([pow(x - avg, 2) for x in numbers]) / \
        float(len(numbers) - 1)
    # print(avg)
    # print(numbers)
    return sqrt(variance)

# Group the data rows under each class yes or


def groupUnderClass(data):
    dict = {}
    for i in range(len(data)):
        if (data[i][-1] not in dict):
            dict[data[i][-1]] = []
        dict[data[i][-1]].append(data[i])
    return dict

# Find Mean and Standard Deviation for any dataset


def MeanAndStdDev(data):
    info = [(mean(attribute), std_dev(attribute))
            for attribute in zip(*data)]
    del info[-1]
    return info

# Find Mean and Standard Deviation under each class


def MeanAndStdDevForClass(data):
    info = {}
    dict = groupUnderClass(data)
    for classValue, instances in dict.items():
        info[classValue] = MeanAndStdDev(instances)
    return info

# Calculate Gaussian Probability Density Function


def calculateGaussianProbability(x, mean, stdev):
    expo = exp(-(pow(x - mean, 2) / (2 * pow(stdev, 2)))) if stdev != 0 else 0
    return (1 / (sqrt(2 * pi) * stdev)) * expo if stdev != 0 else 1

# Calculate Class Probabilities


def calculateClassProbabilities(info, test):
    probabilities = {}
    for classValue, classSummaries in info.items():
        probabilities[classValue] = 1
        for i in range(len(classSummaries)):
            mean, std_dev = classSummaries[i]
            x = test[i]
            probabilities[classValue] *= calculateGaussianProbability(
                x, mean, std_dev)
    return probabilities


def predict(info, test):
    probabilities = calculateClassProbabilities(info, test)
    bestLabel, bestProb = None, -1
    for classValue, probability in probabilities.items():
        if bestLabel is None or probability > bestProb:
            bestProb = probability
            bestLabel = classValue
    return bestLabel


# Returns predictions for a set of examples

def getPredictions(info, test):
    predictions = []
    for i in range(len(test)):
        result = predict(info, test[i])
        predictions.append(result)
    return predictions


"""
Implementing Naive Bayes Classifier
"""
info = MeanAndStdDevForClass(train)
predictions = getPredictions(info, test)
print(
    f"Categorical value obtained from custom Naive Bayes Classifier : {CATEGORY_ENCODING[predictions[0]]}\n")
    
from sklearn.naive_bayes import GaussianNB

gnb = GaussianNB()

X_train = [i[0:-1] for i in dataset]
y_train = [CATEGORY_ENCODING.index(i[-1]) for i in dataset]


gnb.fit(X_train, y_train)

# making predictions on the testing set
y_pred = gnb.predict(test)
print(
    f"Categorical value obtained from sklearn Naive Bayes Classifier : {CATEGORY_ENCODING[y_pred[0]]}")
