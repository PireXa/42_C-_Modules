#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materia[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		~MateriaSource();
		MateriaSource & operator=(MateriaSource const & rhs);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
