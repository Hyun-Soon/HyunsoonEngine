#include "Item.h"

namespace hs
{
	class Meso : public Item
	{
	public:
		Meso();
		~Meso();

	private:
		uint32_t mAmount;
	};

} // namespace hs