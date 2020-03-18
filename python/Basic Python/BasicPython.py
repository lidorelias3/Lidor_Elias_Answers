# exercise 1
def combine_arrays(first_array, second_array):
    combined = []
    for i in range(max(len(first_array), len(second_array))):
        combined.append(
            (first_array[i] if i < len(first_array) else None, second_array[i] if i < len(second_array) else None))
    return combined


# exercise 2
def combine_tuples(tuple_list):
    dict = {}
    for key, val in tuple_list:
        dict[key] = val
    return dict


# exercise 3
def combine_arrays_no_loop(first_array, second_array):
    return tuple(zip(first_array, second_array))


# exercise 3
def combine_tuples_no_loop(tuple_list):
    return dict(tuple_list)


# exercise 4
def lists_to_dict(keys_list, values_list):
    return dict(zip(keys_list, values_list))


# exercise 5
def lists_to_dict_diff_length(keys_list, values_list):
    return dict(zip(keys_list, values_list))


# Test
print(combine_arrays([1, 2, 3, 4, 6, 5], [5, 6, 7, 8, 5, 'a']))
print(combine_arrays_no_loop([1, 2, 3, 4, 6, 5], [5, 6, 7, 8, 5, 'a']))
print(combine_tuples([(1, 10), (2, 20), (3, 30)]))
print(combine_tuples_no_loop([(1, 10), (2, 20), (3, 30)]))
print(lists_to_dict([1, 2, 3], [100, 200, 300]))
print(lists_to_dict_diff_length([1, 2, 3, 4], [100, 200]))
