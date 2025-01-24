
namespace ImGuiExtra
{
    static const float CurveTerminator = -10000;
    enum TYPE
    {
        LINEAR,
        QUADIN,
        QUADOUT,
        QUADINOUT,
        CUBICIN,
        CUBICOUT,
        CUBICINOUT,
        QUARTIN,
        QUARTOUT,
        QUARTINOUT,
        QUINTIN,
        QUINTOUT,
        QUINTINOUT,
        SINEIN,
        SINEOUT,
        SINEINOUT,
        EXPOIN,
        EXPOOUT,
        EXPOINOUT,
        CIRCIN,
        CIRCOUT,
        CIRCINOUT,
        ELASTICIN,
        ELASTICOUT,
        ELASTICINOUT,
        BACKIN,
        BACKOUT,
        BACKINOUT,
        BOUNCEIN,
        BOUNCEOUT,
        BOUNCEINOUT,
        SINESQUARE,
        EXPONENTIAL,
        SCHUBRING1,
        SCHUBRING2,
        SCHUBRING3,
        SINPI2,
        SWING,
    };
    int Curve(const char* label, const ImVec2& size, const int maxpoints, ImVec2* points, int* selection = nullptr, const ImVec2& rangeMin = ImVec2(0, 0), const ImVec2& rangeMax = ImVec2(1, 1));
    float CurveValue(float p, int maxpoints, const ImVec2* points);
    float CurveValueSmooth(float p, int maxpoints, const ImVec2* points);
    void SanityCheck(const char* text);
};