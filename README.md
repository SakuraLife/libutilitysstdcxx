# libutilitysstdc++

### utility sub standard library, A library like and replace stl with only c++ support.

--------
Now is public domain, maybe change license to LGPLv2 if needed.  

libutilitysstdc++ have many implement defined interfaces and some light-weight extensions. It's a portable posix interface library.

### state table

module container
| submodule       | header                  | state | test | 
|:---------------:|:-----------------------:|:-----:|:----:|
| helper          | container_helper.hpp    | D | - |
| helper          | initializer_list.hpp    | D | - |
| array           | array.hpp               | F | P |
| array           | cycle_array.hpp         | U | N |
| dynamic_array   | vector.hpp              | F | P |
| dynamic_array   | deque.hpp               | F | F |
| tuple           | pair.hpp                | F | P |
| tuple           | compressed_pair.hpp     | F | P |
| tuple           | tripair.hpp             | F | P |
| tuple           | tuple.hpp               | F | P |
| tuple           | variant.hpp             | U | N |
| list            | list.hpp                | F | P |
| list            | white_black_tree.hpp    | F | P |
| tree            | set.hpp                 | F | P |
| tree            | multiset.hpp            | F | P |
| tree            | map.hpp                 | F | P |
| tree            | multimap.hpp            | F | P |
| hash            | hash_table.hpp          | F | P |
| hash            | unordered_set.hpp       | P | - |
| hash            | unordered_multiset.hpp  | P | - |
| hash            | unordered_map.hpp       | P | - |
| hash            | unordered_multimap.hpp  | P | - |
| utility         | any.hpp                 | F | P |
| utility         | optional.hpp            | F | P |
| utility         | span.hpp                | P | - |
| adaptor         | queue.hpp               | F | P |
| adaptor         | priority_queue.hpp      | F | P |
| heap            | -------                 | P | - |


module charS
| submodule         | header                    | state | test | 
|:-----------------:|:-------------------------:|:-----:|:----:|
| string            | char_traits.hpp           | F | P |
| string            | basic_string.hpp          | F | P |
| string            | basic_string_builder.hpp  | P | - |
| string            | basic_string_view.hpp     | F | P |
| string            | basic_static_string.hpp   | F | P |
| itoa              | itoa.hpp                  | F | U |

module functional
| submodule       | header                | state | test | 
|:---------------:|:---------------------:|:-----:|:----:|
| function        | function.hpp          | F | P |
| invoke          | invoke.hpp            | F | P |
| binder          | bind.hpp              | F | P |
| binder          | is_placeholders.hpp   | F | P |
| binder          | mem_fn.hpp            | F | P |
| binder          | placeholders.hpp      | F | P |
| wrapper         | cref.hpp              | F | U |
| wrapper         | ref.hpp               | F | U |
| wrapper         | reference_wrapper.hpp | F | P |

module iterator
| submodule       | header                    | state | test | 
|:---------------:|:-------------------------:|:-----:|:----:|
| trait           | iterator_tag.hpp          | F | P |
| trait           | iterator_traits.hpp       | F | P |
| move            | advance.hpp               | F | P |
| move            | next.hpp                  | F | P |
| move            | prev.hpp                  | F | P |
| move            | distance.hpp              | F | P |
| iterator        | base_iterator.hpp         | F | N |
| iterator        | move_iterator.hpp         | F | P |
| iterator        | raw_pointer_iterator.hpp  | F | N |
| iterator        | reverse_iterator.hpp      | F | P |

module memory
| submodule       | header                            | state | test | 
|:---------------:|:---------------------------------:|:-----:|:----:|
| helper          | allocator.hpp                     | D | - |
| trait           | allocator_traits.hpp              | F | P |
| trait           | uses_allocator.hpp                | F | P |
| address         | addressof.hpp                     | F | P |
| allocator       | allocator_helper.hpp              | F | P |
| allocator       | basic_allocator.hpp               | F | P |
| deletor         | basic_deallocator.hpp             | F | P |
| deletor         | default_delete.hpp                | F | P |
| smart_ptr       | unique_ptr.hpp                    | F | P |
| smart_ptr       | observer_ptr.hpp                  | F | P |
| uninitialized   | uninitialized_copy.hpp            | F | N |
| uninitialized   | uninitialized_copy_n.hpp          | F | N |
| uninitialized   | uninitialized_fill.hpp            | F | N |
| uninitialized   | uninitialized_fill_n.hpp          | F | N |
| uninitialized   | uninitialized_move.hpp            | F | N |
| uninitialized   | uninitialized_move_n.hpp          | F | N |
| uninitialized   | uninitialized_possible_move.hpp   | F | N |
| uninitialized   | uninitialized_possible_move_n.hpp | F | N |
| memory          | new.hpp                           | P | - |
| memory          | raw_delete.hpp                    | P | - |
| memory          | destroy.hpp                       | P | - |
| memory          | destroy_n.hpp                     | P | - |
| memory          | destroy_at.hpp                    | P | - |
| buffer          | temporary_buffer.hpp              | F | P |

module math
| submodule       | header                    | state | test | 
|:---------------:|:-------------------------:|:-----:|:----:|
| helper          | math_helper.hpp           | D | - |
| bit             | bitset.hpp                | U | - |
| HP              | cppint.hpp                | P | - |
| SPMF            | ------                    | P | - |

module trait
| submodule       | header                            | state | test | 
|:---------------:|:---------------------------------:|:-----:|:----:|
| helper          | trait_helper.hpp                  | D | - |

module algorithm
| submodule       | header                            | state | test | 
|:---------------:|:---------------------------------:|:-----:|:----:|
| core            | swap.hpp                          | F | P |
| core            | move.hpp                          | F | P |
| core            | forward.hpp                       | F | P |
| core            | possible_swap.hpp                 | F | P |
| core            | algorithm_auxiliary.hpp           | F | P |
| core            | hash.hpp                          | F | N |
| check           | all_of.hpp                        | F | P |
| check           | any_of.hpp                        | F | P |
| check           | none_of.hpp                       | F | P |
| check           | count.hpp                         | F | N |
| check           | count_if.hpp                      | F | N |
| check           | mismatch.hpp                      | F | N |
| search          | find.hpp                          | F | N |
| search          | find_if.hpp                       | F | N |
| search          | find_if_not.hpp                   | F | N |
| search          | find_first_of.hpp                 | F | N |
| search          | find_end.hpp                      | F | N |
| search          | adjacent_find.hpp                 | F | N |
| search          | search.hpp                        | F | N |
| search          | search_n.hpp                      | F | N |
| search          | binary_search.hpp                 | F | N |
| search          | lower_bound.hpp                   | F | N |
| search          | upper_bound.hpp                   | F | N |
| search          | equal_range.hpp                   | P | - |
| compare         | equal.hpp                         | F | N |
| compare         | lexicographical_compare.hpp       | F | N |
| compare         | max.hpp                           | U | D |
| compare         | min.hpp                           | U | D |
| compare         | minmax.hpp                        | P | - |
| compare         | max_element.hpp                   | P | - |
| compare         | min_element.hpp                   | P | - |
| compare         | minmax_element.hpp                | P | - |
| compare         | clamp.hpp                         | P | - |
| compare         | exchange.hpp                      | F | N |
| operate         | for_each.hpp                      | F | N |
| operate         | for_each_n.hpp                    | F | N |
| operate         | transform.hpp                     | F | N |
| copy            | copy.hpp                          | F | N |
| copy            | copy_if.hpp                       | F | N |
| copy            | copy_n.hpp                        | F | N |
| copy            | copy_backward.hpp                 | F | N |
| copy            | move_forward.hpp                  | F | N |
| copy            | move_backward.hpp                 | F | N |
| copy            | move_if_noexcept.hpp              | F | P |
| fill            | fill.hpp                          | F | N |
| fill            | fill_n.hpp                        | F | N |
| fill            | generate.hpp                      | P | - |
| fill            | generate_n.hpp                    | P | - |
| remove          | remove.hpp                        | P | - |
| remove          | remove_if.hpp                     | P | - |
| remove          | remove_copy.hpp                   | P | - |
| remove          | remove_copy_if.hpp                | P | - |
| remove          | replace.hpp                       | P | - |
| remove          | replace_if.hpp                    | P | - |
| remove          | replace_copy.hpp                  | P | - |
| remove          | replace_copy_if.hpp               | P | - |
| remove          | unique.hpp                        | P | - |
| remove          | unique_copy.hpp                   | P | - |
| swap            | swap_ranges.hpp                   | F | P |
| swap            | iter_swap.hpp                     | F | N |
| shuffle         | reverse_copy.hpp                  | F | N |
| shuffle         | reverse.hpp                       | F | N |
| shuffle         | rotate_copy.hpp                   | F | N |
| shuffle         | rotate.hpp                        | F | N |
| shuffle         | random_shuffle.hpp                | P | - |
| shuffle         | shuffle.hpp                       | P | - |
| shuffle         | is_permutation.hpp                | F | N |
| shuffle         | next_permutation.hpp              | P | - |
| shuffle         | prev_permutation.hpp              | P | - |
| partition       | is_partitioned.hpp                | F | N |
| partition       | partition.hpp                     | P | - |
| partition       | partition_copy.hpp                | P | - |
| partition       | stable_partition.hpp              | P | - |
| partition       | partition_point.hpp               | P | - |
| sort            | is_sorted.hpp                     | F | N |
| sort            | is_sort_until.hpp                 | F | N |
| sort            | sort.hpp                          | F | N |
| sort            | partial_sort.hpp                  | F | N |
| sort            | partial_sort_copy.hpp             | P | - |
| sort            | stable_sort.hpp                   | P | - |
| sort            | nth_element.hpp                   | P | - |
| set             | merge.hpp                         | F | N |
| set             | inplace_merge.hpp                 | P | - |
| set             | set_difference.hpp                | P | - |
| set             | set_intersection.hpp              | P | - |
| set             | set_symmetric_difference.hpp      | P | - |
| set             | set_union.hpp                     | P | - |
| heap            | heap.hpp                          | U | D |

heap need *is_heap* and *is_heap_util*

state  
P - prepare;  
F - finished;  
U - unfinished;  
D - developing;

test  
P - pass test;  
D - pass part test;  
F - fail test;  
N - not test;  

### libutility (extensions for libutilitysstdc++ and some useful tools)
  
string_builder support: sync string build class (not a string, without some access functions)  
generate langange parser: use a mark language(see railway diagrams) to analyze all language(or just analyze the setting file the library used.)  
soucre_location(as a library TS2 class, which needs compiler support heavily...)  
Compression support  
crypto support  
enhanced support for cstdlib, cctypes(such as is_num) and other original C library (not include i/o function, will optimize at sstdc++ for safe and extend resons, please search to get answer)  
posix interface support(I think it should be in the sstdc++?)  
and something I forget...  
