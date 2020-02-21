#include <random>
#include <time.h>

class Die {

	public:
			
	Die(int faces) {
		_faces = faces;
		
		_fixRM = _rng.max() %faces != 0;
		_rng = std::default_random_engine(time(NULL));
	}

	int roll(){
		int res = _rng();
		if (_fixRM)
			if (res == _rng.max())
				res = roll();
		return res%_faces +1;
	}
	
	private:
	bool _fixRM;	
	int _faces;
	std::default_random_engine _rng;


} d4(4), d6(6), d8(8), d10(10), d12(12), d20(20), d100(100); 


