/*
 * =====================================================================================
 *
 *       Filename:  flood-fill.cpp
 *
 *    Description:  Flood Fill
 *
 *        Version:  1.0
 *        Created:  11/26/18 09:29:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ricky (), 
 *   Organization:  
 *
 * =====================================================================================
 */

ffill(int u, Graph &g, vi &grid, int target_x, int stop_x) {
    if(grid[u] != target_x) return;

    
    /*  IMPT: to prevent cycles */
    grid[u] = stop_x;
    //For counting the size of component:
    //ans = 1;
    for(auto nbor : g[u]) {
        ffill(nbor, g, grid, target_x, stop_x); 
        //ans += ffill(nbor, g, grid, target_x, stop_x); 
    }

    //return ans;
}

