#include "geometry.h"

Geometry::Geometry() : mFileName(),
    mFilePath(),
    mModelMatrix(),
    mColorBuffer(0),
    mNormalBuffer(0),
    mTexCoordBuffer(0),
    mVertexBuffer(0),
    mVertexArray(0),
    mPrimitiveType(POINTS),
    mVertices(),
    mNormals(),
    mTexCoords(),
    mColors(),
    mScaleFactor(1.0f)

{
    initOpenGLBuffers();

    initDefaultShader();
}

Geometry::Geometry(std::string m_FilePath) : mFileName(),
    mFilePath(m_FilePath),
    mColorBuffer(0),
    mNormalBuffer(0),
    mTexCoordBuffer(0),
    mVertexBuffer(0),
    mVertexArray(0),
    mPrimitiveType(POINTS),
    mVertices(),
    mNormals(),
    mTexCoords(),
    mColors(),
    mScaleFactor(1.0f)

{
    initOpenGLBuffers();

    initDefaultShader();

    this->parseFile();
}

void Geometry::translate(Vector3 m_Translation)
{
    /**
     *  @todo assignment two
     *  add the new translation to the old one
     */
	translation[12]=m_Translation.x;
	translation[13]=m_Translation.y;
	translation[14]=m_Translation.z;

	translation.print();
}

void Geometry::scaleX(float m_ScaleFactor)
{
    /**
     *  @todo assignment two
     *  add the new scale x to the old one
     */
	scale[0]=m_ScaleFactor;
}

void Geometry::scaleY(float m_ScaleFactor)
{
    /**
     *  @todo assignment two
     *  add the new scale y to the old one
     */
	scale[5]=m_ScaleFactor;
}

void Geometry::scaleZ(float m_ScaleFactor)
{
    /**
     *  @todo assignment two
     *  add the new scale z to the old one
     */
	scale[10]=m_ScaleFactor;
}

void Geometry::rotateX(float m_Degrees)
{
    /**
     *  @todo assignment two
     *  add the new rotate x to the old one
     */
	rotationX[5]=cos(m_Degrees);
	rotationX[10]=cos(m_Degrees);
	rotationX[9]=-sin(m_Degrees);
	rotationX[6]=sin(m_Degrees);
}

void Geometry::rotateY(float m_Degrees)
{
    /**
     *  @todo assignment two
     *  add the new rotate y to the old one
     */
	rotationY[0]=cos(m_Degrees);
	rotationY[10]=cos(m_Degrees);
	rotationY[2]=-sin(m_Degrees);
	rotationY[8]=sin(m_Degrees);
}

void Geometry::rotateZ(float m_Degrees)
{
    /**
     *  @todo assignment two
     *  add the new rotate z to the old one
     */
	rotationZ[0]=cos(m_Degrees);
	rotationZ[5]=cos(m_Degrees);
	rotationZ[4]=-sin(m_Degrees);
	rotationZ[1]=sin(m_Degrees);
}

void Geometry::createModelMatrix(bool m_UsePostMultiply)
{
    /**
     *  @todo assignment two
     * create the model matrix based on the translate, scale and rotation values
     * stored as class members.
     * @param m_UsePostMultiply defines if the single transformation matrices have to be
     * premultiplied or postmultiplied to build the final transformation matrix.
     * store the matrix in mModelMatrix
     */

	// concatenation order: translate * rotate * scale
	if (m_UsePostMultiply) {
		mModelMatrix = ((((scale  * rotationX) * rotationY) * rotationZ) * translation);
	} else {
		mModelMatrix = ((((translation * rotationX) * rotationY) * rotationZ) * scale);
	}
}
