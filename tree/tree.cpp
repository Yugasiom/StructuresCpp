#include "tree.hpp"


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


TreeNode **find_max_tree_node(TreeNode *);
TreeNode **find_min_tree_node(TreeNode *);
TreeNode **find_replacement(TreeNode **, int32_t *);


void print_tree_node_(TreeNode *tree_node, int32_t height)
{
	if(tree_node == NULL) {
		return;
	}

	print_tree_node_(tree_node->left, height + 1);
	printf("%ld_%hhd_%d  ", tree_node->data, tree_node->balance_factor, height);
	print_tree_node_(tree_node->right, height + 1);
}

void print_tree_node_2(TreeNode *current, TreeNode *parent, int32_t height)
{
	if(current != NULL) {
		print_tree_node_2(current->left, current, height + 1);
		printf("%ld_%hhd_%d: %ld_%hhd_%d\n", parent->data, parent->balance_factor, height,
		       current->data, current->balance_factor, height + 1);
		print_tree_node_2(current->right, current, height + 1);
	}
}

void print_tree_node2(TreeNode *tree_node)
{
	if(tree_node != NULL) {
		print_tree_node_2(tree_node->left, tree_node, 2);
		printf("\nRoot: %ld_%hhd_%d\n\n", tree_node->data, tree_node->balance_factor, 1);
		print_tree_node_2(tree_node->right, tree_node, 2);
		fflush(stdout);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

TreeNode *create_tree_node(int64_t input_data)
{
	TreeNode *tree_node = (TreeNode *)malloc(sizeof(TreeNode));
	if(tree_node == NULL) {
		return NULL;
	}

	tree_node->data = input_data;
	tree_node->balance_factor = 0;
	tree_node->left = NULL;
	tree_node->right = NULL;

	return tree_node;
}

void free_tree_node(TreeNode *tree_node)
{
	if(tree_node != NULL) {
		TreeNode *left = tree_node->left;
		TreeNode *right = tree_node->right;
		free(tree_node);
		free_tree_node(left);
		free_tree_node(right);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

void free_this_tree_node(TreeNode *tree_node)
{
	if(tree_node != NULL) {
		free(tree_node);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

void print_tree_node(TreeNode *tree_node)
{
	if(tree_node != NULL) {
		print_tree_node_(tree_node, 1);
		printf("\n\n");
		fflush(stdout);
	} else {
		container_error = CONTAINER_NOT_PROVIDED;
	}
}

void balance_tree_node(TreeNode **root)
{
	if(*root == NULL) {
		return;
	}

	if((*root)->balance_factor > 1) {
		if((*root)->right->balance_factor < 0) {
			(*root)->right = rotate_right_tree_node((*root)->right);
		}

		*root = rotate_left_tree_node(*root);
	} else if((*root)->balance_factor < -1) {
		if((*root)->left->balance_factor > 0) {
			(*root)->left = rotate_left_tree_node((*root)->left);
		}

		*root = rotate_right_tree_node(*root);
	}
}

int32_t insert_tree_node(TreeNode **root, TreeNode *new_node)
{
	if(*root == NULL) {
		*root = new_node;

		return 1;
	}

	int32_t old_factor = (*root)->balance_factor;

	if(new_node->data < (*root)->data) {
		int32_t result = insert_tree_node(&(*root)->left, new_node);
		if(result == 1) {
			(*root)->balance_factor -= 1;
			if((*root)->balance_factor < -1) {
				balance_tree_node(root);
			}
		}
	} else {
		int32_t result = insert_tree_node(&(*root)->right, new_node);
		if(result == 1) {
			(*root)->balance_factor += 1;
			if((*root)->balance_factor > 1) {
				balance_tree_node(root);
			}
		}
	}

	return (*root)->balance_factor != 0 && old_factor == 0 ? 1 : 0;
}

void insert_tree_value(TreeNode **tree_node, int64_t input_data)
{
	TreeNode **current_ptr = tree_node;
	if(current_ptr == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return;
	}

	TreeNode *new_tree_node = create_tree_node(input_data);

	insert_tree_node(tree_node, new_tree_node);
}

TreeNode *find_tree_node(TreeNode *tree_node, int64_t input_data)
{
	if(tree_node == NULL || tree_node->data == input_data) {
		return tree_node;
	}

	if(input_data < tree_node->data) {
		return find_tree_node(tree_node->left, input_data);
	} else {
		return find_tree_node(tree_node->right, input_data);
	}
}

int64_t remove_tree_node2(TreeNode **current, int64_t input_data)
{
	if(*current == NULL) {
		return CONTAINER_NOT_PROVIDED;
	}

	if(input_data == (*current)->data) {
		if((*current)->left == NULL && (*current)->right == NULL) {
			free_this_tree_node(*current);
			*current = NULL;

			return 1;
		} else if((*current)->left != NULL && (*current)->right != NULL) {
			TreeNode **replacement = find_min_tree_node((*current)->right);
			(*current)->data = (*replacement)->data;
			int64_t temp = remove_tree_node2(replacement, (*replacement)->data);
			if(temp == 1) {
				(*current)->balance_factor -= 1;
			}
		} else {
			TreeNode *child = (*current)->left != NULL ? (*current)->left : (*current)->right;
			free_this_tree_node(*current);
			*current = child;

			return 1;
		}
	} else {
		if(input_data < (*current)->data) {
			int32_t result = remove_tree_node2(&((*current)->left), input_data);
			if(result == 1) {
				(*current)->balance_factor += 1;
				if((*current)->balance_factor > 1) {
					balance_tree_node(current);
				}
			}
		} else {
			int32_t result = remove_tree_node2(&((*current)->right), input_data);
			if(result == 1) {
				(*current)->balance_factor -= 1;
				if((*current)->balance_factor < -1) {
					balance_tree_node(current);
				}
			}
		}
	}

	return (*current)->balance_factor != 0 ? 1 : 0;
}

int32_t remove_tree_value(TreeNode **root, int64_t value)
{
	if(!root || !*root) {
		return 0;
	}

	if(value < (*root)->data) {
		if(!remove_tree_value(&(*root)->left, value)) {
			return 0;
		}
	} else if(value > (*root)->data) {
		if(!remove_tree_value(&(*root)->right, value)) {
			return 0;
		}
	} else {
		TreeNode *node = *root;

		if(!node->left || !node->right) {
			TreeNode *child = node->left ? node->left : node->right;
			free(node);
			*root = child;
			if(*root) {
				balance_tree_node(root);
			}

			return 1;
		}

		TreeNode **succ = &(*root)->right;
		while((*succ)->left) {
			succ = &(*succ)->left;
		}

		(*root)->data = (*succ)->data;
		remove_tree_value(succ, (*succ)->data);
	}

	balance_tree_node(root);

	return 1;
}

void remove_tree_node(TreeNode **tree_node, int64_t input_data)
{
	if(*tree_node == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return;
	}

	TreeNode *current = *tree_node;
	TreeNode *parent = NULL;
	while(current != NULL && current->data != input_data) {
		parent = current;
		if(input_data < current->data) {
			current = current->left;
		} else {
			current = current->right;
		}
	}

	if(current == NULL) {
		return;
	}

	remove_tree_value(tree_node, input_data);
}

TreeNode **find_max_tree_node(TreeNode *root)
{
	if(root == NULL) {
		return NULL;
	}

	TreeNode **current = &root;
	while((*current)->right != NULL) {
		current = &((*current)->right);
	}

	return current;
}

TreeNode **find_min_tree_node(TreeNode *root)
{
	if(root == NULL) {
		return NULL;
	}

	TreeNode **current = &root;
	while((*current)->left != NULL) {
		current = &((*current)->left);
	}

	return current;
}


TreeNode **find_replacement(TreeNode **root, int32_t *side)
{
	if(root == NULL) {
		container_error = CONTAINER_NOT_PROVIDED;

		return NULL;
	}

	if((*root)->left != NULL) {
		TreeNode **tmp = find_max_tree_node((*root)->left);
		if(tmp != NULL) {
			*side = -1;

			return tmp;
		}
	} else if((*root)->right != NULL) {
		TreeNode **tmp = find_min_tree_node((*root)->right);
		if(tmp != NULL) {
			*side = 1;

			return tmp;
		}
	}

	*side = 0;

	return NULL;
}

int32_t get_balance_factor(TreeNode * node)
{
	if(node == NULL) {
		return 0;
	}

	return node->balance_factor;
}

void update_height(TreeNode * tree_node)
{
	if(tree_node != NULL) {
		tree_node->balance_factor = 1 + max(get_balance_factor(tree_node->left), get_balance_factor(tree_node->right));
	}
}

TreeNode *rotate_left_tree_node(TreeNode *root)
{
	if(root == NULL) {
		return NULL;
	}

	TreeNode *new_root = root->right;
	root->right = new_root->left;
	new_root->left = root;

	root->balance_factor = root->balance_factor - 1 - max(0, new_root->balance_factor);
	new_root->balance_factor = new_root->balance_factor - 1 + min(0, root->balance_factor);

	return new_root;
}

TreeNode *rotate_right_tree_node(TreeNode *root)
{
	if(root == NULL) {
		return NULL;
	}

	TreeNode *new_root = root->left;
	root->left = new_root->right;
	new_root->right = root;

	root->balance_factor = root->balance_factor + 1 - min(0, new_root->balance_factor);
	new_root->balance_factor = new_root->balance_factor + 1 + max(0, root->balance_factor);

	return new_root;
}
