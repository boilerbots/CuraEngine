//Copyright (c) 2017 Ultimaker B.V.
//CuraEngine is released under the terms of the AGPLv3 or higher.

#include "FractalInfillTest.h"
#include "../src/infill/SquareSubdivision.h"
#include "../src/infill/ImageBasedDensityProvider.h"

namespace cura
{
    CPPUNIT_TEST_SUITE_REGISTRATION(FractalInfillTest);

void FractalInfillTest::setUp()
{
    // no dothing
}

void FractalInfillTest::tearDown()
{
    // no dothing
}

void FractalInfillTest::debugCheck()
{
    coord_t line_width = 400;
    int max_depth = 8;
    AABB3D aabb_3d(Point3(0, 0, 0), Point3(line_width, line_width, line_width) * 512);
    AABB aabb = aabb_3d.flatten();
    std::cerr << "AABB: " << aabb.max << "\n";
    
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/lena.png", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/gradient.png", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/slight_gradient.png", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/simple.png", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/gray.png", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/triangle.png", aabb);

//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/hitler.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/cheshire_cat.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/vader.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/sinterklaas.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/diamond.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/trex.jpeg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/bagelorb.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/soulpilot.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/soulpilot_dark.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/cura-logo.jpg", aabb);
    DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/T-shirt-printing/input/deer.png", aabb_3d);
    
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/nessy.jpg", aabb);
//     DensityProvider* subdivider = new ImageBasedDensityProvider("/home/t.kuipers/Documents/PhD/Fractal Dithering project/input images/smize.png", aabb);
    
    bool consecutivity_constraint = false;
    SquareSubdivision ss(*subdivider, aabb, max_depth, line_width, consecutivity_constraint);
    ss.initialize();
//     ss.subdivideUpto(2);
//     ss.createMinimalErrorPattern(false);
    ss.createDitheredPattern();
//     ss.createMinimalDensityPattern();
    ss.debugCheck();
    
    {
        Point canvas_size = Point(1024, 1024);
        SVG svg("output/subdiv_dither.svg", aabb, canvas_size);
        
        bool draw_arrows = false;
        float drawing_line_width = static_cast<float>(line_width) * svg.getScale();
        if (draw_arrows) drawing_line_width *= .2;
        
        
//         ss.debugOutput(svg, drawing_line_width, draw_arrows);
//         ss.outputHilbert(svg, drawing_line_width * 2);
        ss.outputMoore(svg, drawing_line_width * 2);
    }
}

}
