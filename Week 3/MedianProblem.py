import heapq

NUMLIST_FILENAME = "median.txt" 

inFile = open(NUMLIST_FILENAME, 'r')

heapLo = [] 
heapHi = [] 
heapq.heapify(heapHi)
heapq.heapify(heapLo)
medians = [] 
with inFile as f:
    for integers in f.readlines():
        num = int(integers.strip())     
        if not heapLo:
            heapq.heappush(heapLo, num * -1)
        else:
            lenHeapLo = len(heapLo)
            lenHeapHi = len(heapHi)
            hiLo = heapq.heappop(heapLo) * -1
            medians.append(hiLo)

            if num <= hiLo:
                if lenHeapLo <= lenHeapHi:
                    heapq.heappush(heapLo, num * -1)
                    heapq.heappush(heapLo, hiLo * -1)
                else:
                    heapq.heappush(heapLo, num * -1)
                    heapq.heappush(heapHi, hiLo)
            else: 
                if lenHeapHi < lenHeapLo:
                    heapq.heappush(heapHi, num)
                    heapq.heappush(heapLo, hiLo * -1)
                else:
                    loHi = heapq.heappop(heapHi)
                    if loHi < num:
                        heapq.heappush(heapHi, num)
                        heapq.heappush(heapLo, loHi * -1)
                        heapq.heappush(heapLo, hiLo * -1)
                    else:
                        heapq.heappush(heapLo, num * -1)
                        heapq.heappush(heapHi, loHi)
                        heapq.heappush(heapLo, hiLo * -1)

medians.append(heapq.heappop(heapLo) * -1)

print('medians', medians)
print('result', sum(medians)%10000)
