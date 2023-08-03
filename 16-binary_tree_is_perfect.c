#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height of
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise or if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (tree->left == NULL && tree->right == NULL)
        return (1);

    if (tree->left && tree->right)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_is_full(tree) && binary_tree_height(tree->left) == binary_tree_height(tree->right));
}

