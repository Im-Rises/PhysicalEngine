#ifndef MATRIX44_H
#define MATRIX44_H

class Matrix44 {
private:

    float m_value[16];
public:
    /// <summary>
    /// Constructeur matrix vide
    /// </summary>
    Matrix44();

    /// <summary>
    /// Constructeur de Matrix Ligne par ligne (0-3) ligne 1 ,(4-7) ligne 2 ...)
    /// </summary>
    /// <param name="m_value"></param>
    Matrix44(float m_value[16]);

    /// <summary>
    /// Accède à un élément ligne i colone j
    /// </summary>
    /// <param name="i"></param>
    /// <param name="j"></param>
    /// <returns></returns>
    float operator()(int i, int j) const;

    /// <summary>
    /// renvoie m_value[i] si on cherche un élément ligne i , colone j faire : [4*i+j]
    /// </summary>
    /// <param name="i"></param>
    /// <returns></returns>
    float operator[](int i) const;

    /// <summary>
    /// produit matriciel de 2 matrices
    /// </summary>
    /// <param name="matrix"></param>
    /// <returns></returns>
    Matrix44 operator*(const Matrix44 &matrix);


    ~Matrix44();

};

#endif // !1MATRIX44_H
