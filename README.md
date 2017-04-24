[Japanese](README_ja.md)/ English

# unordered_map for memoization

## Summary

Suppose we want to calculate some value for some key.
Since the calculation of the value is relatively heavy,
we want to memoize the value.
While we can use `std::map` or `std::unordered_map` for such purpose,
we want to limit the maximum number of elements.
Therefore, I prepare a map which halves its data
when the number of elements reaches the specified value.

## How to use

Use in the same way as `std::map`, for example,

```
memo_map<int, int> m(100000);

int
func(int key){
  if(m.has_key(key))return m[key];
  else return calculate_value_of(key);
}
```

## Usage

The map for memoization `memo_map` becomes available by including `memo_map.hpp`.
You can use `memo_map` in the same way as `std::unordered_map`. But you have to specify the maximum number of elements to its constructor.
If the number of elements reaches the speficied number,
`memo_map` sort the data by value and keeps only upper half of them.

## Sample

Here are two samples.

* `test_int.cpp` A sample of `memo_map<std::string, int>`
* `test_double.cpp` A sample of `memo_map<std::string, double>`


Here are the results of `test_int.cpp`.

    $ make
    $ ./test_int
    Input Data
    test000->082
    test001->013
    test002->091
    test003->084
    test004->012
    test005->097
    test006->092
    test007->022
    test008->063
    test009->031
    test010->009
    test011->055
    test012->028
    test013->019
    test014->055
    test015->100
    test016->096
    test017->100
    test018->097
    test019->097
    Cached Data
    test000->082
    test003->084
    test002->091
    test006->092
    test016->096
    test005->097
    test019->097
    test018->097
    test017->100
    test015->100    

And here are the results of `test_double.cpp`.

    $ make
    $ ./test_double
    Input Data
    test000->0.1355
    test001->0.8350
    test002->0.9689
    test003->0.2210
    test004->0.3082
    test005->0.5472
    test006->0.1884
    test007->0.9929
    test008->0.9965
    test009->0.9677
    test010->0.7258
    test011->0.9811
    test012->0.1099
    test013->0.7981
    test014->0.2970
    test015->0.0048
    test016->0.1125
    test017->0.6398
    test018->0.8784
    test019->0.0000
    Cached Data
    test019->0.0000
    test010->0.7258
    test013->0.7981
    test001->0.8350
    test018->0.8784
    test009->0.9677
    test002->0.9689
    test011->0.9811
    test017->0.6398
    test007->0.9929
    test008->0.9965

In both sample, the maximum number of elements is set to be 20.
When the 20th element is added, then `memo_map` reduces its data so that the upper half of values are remained. After the reduction, the 20th element is added. Therefore, the last pair, `test019->0.0000` is remained in `Cached Data`.
