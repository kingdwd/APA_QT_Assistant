#ifndef HC00_REEDSSHEPPSTATESPACE_H
#define HC00_REEDSSHEPPSTATESPACE_H

#include <limits>
#include <memory>
#include <vector>

#include "Planning/Interface/hc_cc_state_space.h"
#include "Planning/Path/hc_cc_circle.h"
#include "Planning/Path/hc_cc_rs_path.h"

#include "Common/Configure/Configs/system_config.h"

using namespace std;
using namespace steering;
using namespace hc_cc_rs;

#define CC_REGULAR false

class HC00_ReedsSheppStateSpace : public HC_CC_StateSpace
{
public:
    /**
     * @brief HC00_ReedsSheppStateSpace Constructor
     * @param kappa :the max curvature of the path
     * @param sigma :the max sharpness of the path
     * @param discretization :the discretization step
     */
    HC00_ReedsSheppStateSpace(double kappa, double sigma, double discretization = 0.1);

    /**
     * @brief Destructor
     */
    virtual ~HC00_ReedsSheppStateSpace();

    /**
     * @brief Returns a sequence of turns and straight lines connecting the two circles c1 and c2
     * @param c1 :start circle
     * @param c2 :end circle
     * @return a sequence of turns and straight line
     */
    HC_CC_RS_Path* HC00_CirclesReedsSheppPath(HC_CC_Circle &c1, HC_CC_Circle &c2);

    /**
     * @brief Returns a sequence of turns and straight lines connecting a start and an end configuration
     * @param state1 :the start state
     * @param state2 :the end state
     * @return a sequence of turns and straight lines
     */
    HC_CC_RS_Path* HC00_ReedsSheppPath(const State &state1, const State &state2);

    /**
     * @brief Returns shortest path length from state1 to state2
     * @param state1 :the start state
     * @param state2 :the end state
     * @return
     */
    double getDistance(const State &state1, const State &state2);

    /**
     * @brief Returns controls of the shortest path from state1 to state2
     * @param state1 :the start state
     * @param state2 :the end state
     * @return
     */
    vector<Control> getControls(const State &state1, const State &state2);

private:

    /**
     * @brief class that contains functions to compute the families
     */
    class HC00_ReedsShepp;

    /**
     * @brief unique pointer on class with families
     */
    unique_ptr<HC00_ReedsShepp> _hc00_reeds_shepp;

    /**
     * @brief Param of a rs-circle
     */
    HC_CC_Circle_Param _rs_circle_param;
};

#endif // HC00_REEDSSHEPPSTATESPACE_H
