//
// Created by aknight on 11/10/19.
//

#include "balanced.h"

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

    Balancer<'(', ')'> balanced_parens;
    Balancer<'{', '}'> balanced_curly;
    Balancer<'[', ']'> balanced_square;
    Balancer<'<', '>'> balanced_angle;

}}}}