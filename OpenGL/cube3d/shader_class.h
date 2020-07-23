#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
    public:
        unsigned int id;

        Shader (const char *vertex_path, const char *fragment_path)
        {
            std::string vertex_code;
            std::string fragment_code;
            std::ifstream v_shader_file;
            std::ifstream f_shader_file;

            v_shader_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
            f_shader_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
            try
            {
                v_shader_file.open (vertex_path);
                f_shader_file.open (fragment_path);
                std::stringstream vShaderStream, fShaderStream;

                vShaderStream << v_shader_file.rdbuf ();
                fShaderStream << f_shader_file.rdbuf ();

                v_shader_file.close ();
                f_shader_file.close ();

                vertex_code = vShaderStream.str ();
                fragment_code = fShaderStream.str ();
            }
            catch (std::ifstream::failure &e)
            {
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            }
            const char *v_shader_code = vertex_code.c_str ();
            const char *f_shader_code = fragment_code.c_str ();

            unsigned int vertex, fragment;

            vertex = glCreateShader (GL_VERTEX_SHADER);
            glShaderSource (vertex, 1, &v_shader_code, NULL);
            glCompileShader (vertex);
            checkCompileErrors (vertex, "VERTEX");

            fragment = glCreateShader (GL_FRAGMENT_SHADER);
            glShaderSource (fragment, 1, &f_shader_code, NULL);
            glCompileShader (fragment);
            checkCompileErrors (fragment, "FRAGMENT");

            id = glCreateProgram ();
            glAttachShader (id, vertex);
            glAttachShader (id, fragment);
            glLinkProgram (id);
            checkCompileErrors (id, "PROGRAM");

            glDeleteShader (vertex);
            glDeleteShader (fragment);
        }

        void use ()
        {
            glUseProgram (id);
        }

        void setBool (const std::string &name, bool value) const
        {
            glUniform1i (glGetUniformLocation (id, name.c_str ()), (int)value);
        }

        void setInt (const std::string &name, int value) const
        {
            glUniform1i (glGetUniformLocation (id, name.c_str ()), value);
        }

        void setFloat (const std::string &name, float value) const
        {
            glUniform1f (glGetUniformLocation (id, name.c_str ()), value);
        }
        void setVec2 (const std::string &name, float x, float y) const
        {
            glUniform2f (glGetUniformLocation (id, name.c_str ()), x, y);
        }
       
        void setVec3 (const std::string &name, const glm::vec3 &value) const
        {
            glUniform3fv (glGetUniformLocation (id, name.c_str ()), 1, &value[0]);
        }
        void setVec3 (const std::string &name, float x, float y, float z) const
        {
            glUniform3f (glGetUniformLocation (id, name.c_str ()), x, y, z);
        }
        
        void setVec4 (const std::string &name, const glm::vec4 &value) const
        {
            glUniform4fv (glGetUniformLocation (id, name.c_str ()), 1, &value[0]);
        }
        void setVec4 (const std::string &name, float x, float y, float z, float w) const
        {
            glUniform4f (glGetUniformLocation (id, name.c_str ()), x, y, z, w);
        }
        
        void setMat2 (const std::string &name, const glm::mat2 &mat) const
        {
            glUniformMatrix2fv (glGetUniformLocation (id, name.c_str ()), 1, GL_FALSE, &mat[0][0]);
        }
       
        void setMat3 (const std::string &name, const glm::mat3 &mat) const
        {
            glUniformMatrix3fv (glGetUniformLocation (id, name.c_str ()), 1, GL_FALSE, &mat[0][0]);
        }
        
        void setMat4 (const std::string &name, const glm::mat4 &mat) const
        {
            glUniformMatrix4fv (glGetUniformLocation (id, name.c_str ()), 1, GL_FALSE, &mat[0][0]);
        }

    private:
        void checkCompileErrors (unsigned int shader, std::string type)
        {
            int success;
            char info_log[1024];

            if (type != "PROGRAM")
            {
                glGetShaderiv (shader, GL_COMPILE_STATUS, &success);
                if (!success)
                {
                    glGetShaderInfoLog (shader, 1024, NULL, info_log);
                    std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << info_log << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
            else
            {
                glGetProgramiv (shader, GL_LINK_STATUS, &success);
                if (!success)
                {
                    glGetProgramInfoLog (shader, 1024, NULL, info_log);
                    std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << info_log << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
        }
};