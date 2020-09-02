from jpype import *
from pyhanlp import *

#startJVM(getDefaultJVMPath(), "-Djava.class.path=D:/Miniconda3/Lib/site-packages/pyhanlp/static/hanlp-1.7.8.jar;D:/Miniconda3/Lib/site-packages/pyhanlpstatic", "-Xms1g", "-Xmx1g") 

def loadDictionary():
    IOUtil = JClass('com.hankcs.hanlp.corpus.io.IOUtil')
    path = HanLP.Config.CoreDictionaryPath.replace('.txt', '.mini.txt')
    dic = IOUtil.loadDictionary([path])
    return set(dic.keySet())

def fullySegment(text, dic):
    wordList = []
    for i in range(len(text)):
        for j in range(i + 1, len(text) + 1):
            word = text[i : j]
            if word in dic:
                wordList.append(word)
    return wordList

def forwardLongestSegment(text, dic):
    wordList = []
    i = 0
    while i < len(text):
        longest_word = text[i]
        for j in range(i + 1, len(text) + 1):
            word = text[i:j]
            if word in dic:
                if len(word) > len(longest_word):
                    longest_word = word
        wordList.append(longest_word)
        i += len(longest_word)
    return wordList

def backwardLongestSegment(text, dic):
    wordList = []
    i = len(text) - 1
    while i >= 0:
        longest_word = text[i]
        for j in range(0, i):
            word = text[j : i + 1]
            if word in dic:
                if len(word) > len(longest_word):
                    longest_word = word
                    break
        wordList.insert(0, longest_word)
        i -= len(longest_word)
    return wordList

def doubleLongestSegment(text, dic):
    forward = forwardLongestSegment(text,dic)
    backward = backwardLongestSegment(text, dic)
    if len(forward) > len(backward):
        return backward
    elif len(forward) < len(backward):
        return forward
    else:
        fwdSingle, bwdSingle = 0, 0
        for word in forward:
            if len(word) == 1:
                fwdSingle += 1
        for word in backward:
            if len(word ) == 1:
                bwdSingle += 1
        if fwdSingle >= bwdSingle:
            return backward
        else:
            return forward

text = '结婚的和尚未结婚的'
dictionary = loadDictionary()
print(fullySegment(text, dictionary))
print(forwardLongestSegment(text, dictionary))
print(backwardLongestSegment(text, dictionary))
print(doubleLongestSegment(text, dictionary))