from sympy import *
from fractions import Fraction

init_printing(order='rev_lex')

eval_mat_1 = Matrix(
    [[1  , 3,],
     [Fraction(1,3), 1]]
)

eigen_val_vects_1 = eval_mat_1.eigenvects()
eigen_val_vects_1

# 固有値と多重度、固有ベクトルのインデックスを保存しておく
EIGEN_VAL_IDX = 0
MULUTIPLICITY_IDX = 1
EIGEN_VEC_IDX = 2

# 最大固有値とその時の多重度・固有ベクトルを取得
max(eigen_val_vects_1, key=(lambda x: x[EIGEN_VAL_IDX]))

eigen_val, multiplicity, eigen_vec = max(eigen_val_vects_1, key=(lambda x: x[EIGEN_VAL_IDX]))
eigen_vec
