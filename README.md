# 0x1D. C - Binary trees

`C`
`Group project`
`Algorithm`
`Data structure`

## Data structures
### Basic Binary Tree

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### Binary Search Tree
`typedef struct binary_tree_s bst_t;`
### AVL Tree
`typedef struct binary_tree_s avl_t;`
### Max Binary Heap
`typedef struct binary_tree_s heap_t;`

## Print function
[this function](https://github.com/holbertonschool/0x1C.c)

# Tasks
## 0. New node

Write a function that creates a binary tree node

  * Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
  * Where `parent` is a pointer to the parent node of the node to create
  * And `value` is the value to put in the new node
  * When created, a node does not have any child
  * Your function must return a pointer to the new node, or `NULL`  on failure
  
## 1. Insert left

Write a function that inserts a node as the left-child of another node

   * Prototype: `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)`;
   * Where `parent` is a pointer to the node to insert the left-child in
   * And `value` is the value to store in the new node
   * Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
   * If `parent` already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.

## 2. Insert right

Write a function that inserts a node as the right-child of another node

   * Prototype:`binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)`;
   * Where `parent` is a pointer to the node to insert the right-child in
   * And `value` is the value to store in the new node
   * Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
   * If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.

## 3. Delete

Write a function that deletes an entire binary tree

   * Prototype: `void binary_tree_delete(binary_tree_t *tree)`;
   * Where `tree` is a pointer to the root node of the tree to delete
   * If `tree` is `NULL`, do nothing
    
## 4. Is leaf

Write a function that checks if a node is a leaf

   * Prototype: `int binary_tree_is_leaf(const binary_tree_t *node)`;
   * Where `node` is a pointer to the node to check
   * Your function must return `1` if `node` is a leaf, otherwise `0`
   * If `node` is `NULL`, return `0`
    
## 5. Is root

Write a function that checks if a given node is a root

   * Prototype: `int binary_tree_is_root(const binary_tree_t *node)`;
   * Where `node` is a pointer to the node to check
   * Your function must return `1` if node is a root, otherwise `0`
   * If `node` is `NULL`, return `0`
    
## 6. Pre-order traversal

Write a function that goes through a binary tree using pre-order traversal

   * Prototype: `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))`;
   * Where `tree` is a pointer to the root `node` of the tree to `traverse`
   * And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
   * If `tree` or `func` is `NULL`, do nothing
   
## 7. In-order traversal

Write a function that goes through a binary tree using in-order traversal

   * Prototype: `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))`;
   * Where `tree` is a pointer to the root node of the tree to traverse
   * And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
   * If `tree` or `func` is `NULL`, do nothing

## 8. Post-order traversal

Write a function that goes through a binary tree using post-order traversal

   * Prototype: `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`
   * Where `tree` is a pointer to the root node of the tree to traverse
   * And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
   * If `tree` or `func` is `NULL`, do nothing

## 9. Height

Write a function that measures the height of a binary tree

   * Prototype: `size_t binary_tree_height(const binary_tree_t *tree);`
   * Where `tree` is a pointer to the root node of the tree to measure the height.
   * If `tree` is `NULL`, your function must return `0`

   
## 10. Depth

Write a function that measures the depth of a node in a binary tree

   * Prototype: `size_t binary_tree_depth(const binary_tree_t *tree);`
   * Where `tree` is a pointer to the node to measure the depth
   * If tree is `NULL`, your function must return `0`

## 11. Size

Write a function that measures the size of a binary tree

   * Prototype: `size_t binary_tree_size(const binary_tree_t *tree);`
   * Where `tree` is a pointer to the root node of the tree to measure the size
   * If `tree` is `NULL`, the function must return `0`
    
## 12. Leaves

Write a function that counts the leaves in a binary tree

   * Prototype: `size_t binary_tree_leaves(const binary_tree_t *tree);`
   *  Where `tree` is a pointer to the root node of the tree to count the number of leaves
   * If `tree` is `NULL`, the function must return `0`
   * A `NULL` pointer is not a leaf
    
## 13. Nodes

Write a function that counts the nodes with at least 1 child in a binary tree

   * Prototype: `size_t binary_tree_nodes(const binary_tree_t *tree);`
   * Where `tree` is a pointer to the root node of the tree to count the number of nodes
   * If `tree` is `NULL`, the function must return `0`
   * A `NULL` pointer is not a `node`
   
## 14. Balance factor

Write a function that measures the balance factor of a binary tree

   * Prototype: `int binary_tree_balance(const binary_tree_t *tree);`
   * Where `tree` is a pointer to the root node of the tree to measure the balance factor
   * If `tree` is `NULL`, return `0`
    
## 15. Is full

Write a function that checks if a binary tree is full

   * Prototype: `int binary_tree_is_full(const binary_tree_t *tree);`
   * Where `tree` is a pointer to the root node of the tree to check
   * If `tree` is `NULL`, your function must return `0`

## 16. Is perfect

Write a function that checks if a binary tree is perfect

  * Prototype: `int binary_tree_is_perfect(const binary_tree_t *tree);`
  * Where `tree` is a pointer to the root node of the tree to check
  * If `tree` is `NULL`, your function must return `0`
    
## 17. Sibling

Write a function that finds the sibling of a node

   * Prototype: `binary_tree_t *binary_tree_sibling(binary_tree_t *node);`
   * Where `node` is a pointer to the `node` to find the `sibling`
   * Your function must return a pointer to the `sibling node`
   * If `node` is `NULL` or the parent is `NULL`, return `NULL`
   * If `node` has no sibling, return `NULL`
    
## 18. Uncle

Write a function that finds the uncle of a node

   * Prototype: `binary_tree_t *binary_tree_uncle(binary_tree_t *node);`
   * Where `node` is a pointer to the `node` to find the `uncle`
   * Your function must `return` a `pointer` to the `uncle node`
   * If `node` is NULL, return `NULL`
   * If `node` has no `uncle`, return `NULL`
    