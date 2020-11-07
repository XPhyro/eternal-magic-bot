# eternal-magic-bot
An application that solves the "Twins Room" puzzle in the video game "Eternal Magic" that is written in C.

This is essentially a re-write of [XPhyro/eternal_magic-bot](https://github.com/XPhyro/eternal_magic-bot). The previous version was written in Python; thus, there is a significant performance difference:
|                       |  5x4  |  5x5  |  6x5  |
|:---------------------:|:-----:|:-----:|:-----:|
|         Python        | 22.8s |  484s |  nope |
| Python Multiprocessed |  4.9s | 50.3s | 3527s |
|        C Debug        | 0.18s |  1.6s |  127s |
|    C Release (-O3)    | 0.11s |  1.2s | 63.1s |

5x4 is the biggest matrix that exists in the game, but the tests were also executed on bigger matrices to see how the programs would compare. All matrices started with all of their elements set to red (0). Versions used were Python 3.8.5 [GCC 10.1.0] and C11 [GCC 10.1.0].

Note that the difference is affected by the Python version being written poorly as much as by the general performance difference between the two languages.
