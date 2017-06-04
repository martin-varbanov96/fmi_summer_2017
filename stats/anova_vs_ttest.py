from scipy.stats import f
from scipy.stats import t
import random
interval = random.randrange(0, 1);
for i in range(0, 100):
    interval_f = random.uniform(0, 1);
    interval_t = 1- ((1 - interval_f)/2) 
    if
        print("f: {0:.4f}, t: {0:.4f}".format(f.ppf(interval_f, 1, 18), t.ppf(interval_t, 18)*t.ppf(interval_t, 18)))
    #print("int_f: {}, int_t : {}", interval_f, interval_t)
print(f.ppf(.95, 1, 18));
print(t.ppf(.975, 18)*t.ppf(.975, 18));