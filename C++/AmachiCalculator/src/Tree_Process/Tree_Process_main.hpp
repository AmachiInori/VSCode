# pragma once
# ifndef __AMI_TPM__
# define __AMI_TPM__

# include "../Parser/Parser_production.hpp"

AMIC_NAMESPACE_START

double calcu_tree_value(T_node::tree_node* root) { 
    try {
        return root->value();
    } catch (const AMICAL_ERROR& err) {
        std::cout << "(Ami003) Math error.\n";
        throw AMICAL_ERROR(err);
    }
}

AMIC_NAMESPACE_END

# endif