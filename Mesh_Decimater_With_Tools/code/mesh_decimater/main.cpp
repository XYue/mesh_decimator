#if !defined(OM_USE_OSG)
#  define OM_USE_OSG 0
#endif

#include "mesh_decimater.h"

int main(int argc, char *argv[])
{
    /*
    case 'D': opt.decorate_name = true;   break;
    case 'd': gdebug            = true;   break;
    case 'h': usage_and_exit(0);
    case 'i': ifname            = optarg; break;
    case 'M': opt.parse_argument( optarg ); break;
    case 'n': opt.n_collapses   = float(atof(optarg)); break;
    case 'o': ofname            = optarg; break;
    case 'v': gverbose          = true;   break;
    case '?':
    default:
    std::cerr << "FATAL: cannot process command line option!"
    << std::endl;
    */

    /*
    std::cerr << "Usage: decimator [Options] -i input-file -o output-file\n"
    << "  Decimating a mesh using quadrics and normal flipping.\n" << std::endl;
    std::cerr << "Options\n"  << std::endl;
    std::cerr << " -M \"{Module-Name}[:Value]}\"\n"
    << "    Use named module with eventually given parameterization\n"
    << "    Several modules can also be used in order to introduce further constraints\n"
    << "    Note that -M has to be given before each new module \n"
    << "    An example with ModQuadric as a priority module\n"
    << "    and ModRoundness as a binary module could look like this:\n"
    << "    commandlineDecimater -M Q -M R:40.0 -n 0.1 -i inputfile.obj -o outputfile.obj\n" << std::endl;
    std::cerr << " -n <N>\n"
    << "    N >= 1: do N halfedge collapses.\n"
    << "    N <=-1: decimate down to |N| vertices.\n"
    << " 0 < N < 1: decimate down to N%.\n" << std::endl;
    std::cerr << std::endl;
    std::cerr << "Modules:\n\n";
    std::cerr << "  AR[:ratio]      - ModAspectRatio\n";
    std::cerr << "  EL[:legth]      - ModEdgeLength*\n";
    std::cerr << "  HD[:distance]   - ModHausdorff\n";
    std::cerr << "  IS              - ModIndependentSets\n";
    std::cerr << "  ND[:angle]      - ModNormalDeviation*\n";
    std::cerr << "  NF[:angle]      - ModNormalFlipping\n";
    std::cerr << "  PM[:file name]  - ModProgMesh\n";
    std::cerr << "  Q[:error]       - ModQuadric*\n";
    std::cerr << "  R[:angle]       - ModRoundness\n";
    std::cerr << "    0 < angle < 60\n";
    std::cerr << "  *: priority module. Decimater needs one of them (not more).\n";
    */

#if OM_USE_OSG
    osg::osgInit( argc, argv );
#endif

    std::string ifname = argv[1]; // "../../data/mesh.ply";
    std::string ofname = argv[2]; // "../../data/test_out.ply";
    int gdebug = 0;
    int gverbose = 0; ///

    DecOptions opt;

    //opt.decorate_name = false; // -D
    opt.n_collapses = atof(argv[3]);// 0.25; // -n 0.1
    std::string value = ""; // "30";
    //opt.init(opt.AR, value);
    //opt.init(opt.EL, value);
    //opt.init(opt.HD, value);
    //opt.init(opt.IS, value);
    //opt.init(opt.ND, value);
    //opt.init(opt.NF, value);
    //opt.init(opt.PM, value);
    opt.init(opt.Q,  value);
    //opt.init(opt.R,  value);

    if ( (-1.0f < opt.n_collapses) &&  (opt.n_collapses < 0.0f) )
    {
        std::cerr << "Error: Option -n: invalid value argument!" << std::endl;
        return 2;
    }

    if (gverbose)
    {
        std::clog << "    Input file: " << ifname << std::endl;
        std::clog << "   Output file: " << ofname << std::endl;
        std::clog << "    #collapses: " << opt.n_collapses << std::endl;
    }

    if (gverbose)
    {
        std::clog << "Begin decimation" << std::endl;
    }

    bool rc = decimate<ArrayTriMesh, Decimater>(ifname, ofname, opt, gverbose);

    if (gverbose)
    {
        if (!rc)
        {
            std::clog << "Decimation failed!" << std::endl;
        }
        else
        {
            std::clog << "Decimation done." << std::endl;
        }
    }

    return 0;
}