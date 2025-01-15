#include "music.h"

NOTE megalovania[] = 
{
		// 1
	{NOTE_D3, time_16th},
	{NOTE_D3, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 2
	{NOTE_C3, time_16th},
	{NOTE_C3, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 3
	{NOTE_C3B, time_16th},
	{NOTE_C3B, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 4
	{NOTE_GS2, time_16th},
	{NOTE_GS2, time_16th},
	{NOTE_D4, time_8th},
	{NOTE_A3, time_8th},
	{REST, time_16th},
	{NOTE_GS3, time_16th},
	{REST, time_16th},
	{NOTE_G3, time_8th},
	{NOTE_F3, time_16th * 2},
	{NOTE_D3, time_16th},
	{NOTE_F3, time_16th},
	{NOTE_G3, time_16th},

		// 5 (remaining part of the song)
};

NOTE pacman_theme[] = 
{
	// 1
	{NOTE_B4, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_C5, time_16th},
	{NOTE_C6, time_16th},
	{NOTE_G5, time_16th},
	{NOTE_E5, time_16th},
	{NOTE_C6, time_16th},
	{NOTE_G5, time_16th},
	{NOTE_E5, time_16th},

	// 2
	{NOTE_B4, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_D5, time_16th},
	{NOTE_D6, time_16th},
	{NOTE_A5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_D6, time_16th},
	{NOTE_A5, time_16th},
	{NOTE_FS5, time_16th},

	// 3
	{NOTE_B4, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_E5, time_16th},
	{NOTE_E6, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_GS5, time_16th},
	{NOTE_E6, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_GS5, time_16th},

	// 4
	{NOTE_B4, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_F5, time_16th},
	{NOTE_F6, time_16th},
	{NOTE_CS6, time_16th},
	{NOTE_A5, time_16th},
	{NOTE_F6, time_16th},
	{NOTE_CS6, time_16th},
	{NOTE_A5, time_16th},

	// Ending
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_B5, time_16th},
	{NOTE_FS5, time_16th},
	{NOTE_DS5, time_16th},
	{NOTE_B4, time_8th},
	{REST, time_8th}
};