from gensim.models import KeyedVectors

model = KeyedVectors.load_word2vec_format('../data/GoogleNews-vectors-negative300.bin', binary=True) 

print(model.vectors.shape)
print(model['United_States'])

with (open('../data/questions-words.txt', 'r') as fr,
      open('../work/questions-words-prediction-server.txt', 'w') as fw):
    for line in fr:
        line = line.rstrip()
        if line[0] == ':':
            fw.write(f'{line}\n')
            continue
        words = line.split(' ')
        pred = model.most_similar(positive=words[1:3], negative=[words[0]], topn=1)
        print(pred[0])
        fw.write(f'{line} {pred[0][0]} {pred[0][1]}\n')