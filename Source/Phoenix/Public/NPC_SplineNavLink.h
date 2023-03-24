#pragma once
#include "CoreMinimal.h"
#include "NPC_JumpSplineData.h"
#include "NPC_Spline.h"
#include "NPC_SplineNavLink.generated.h"

class USplineNavLinkComponent;

UCLASS(Blueprintable)
class ANPC_SplineNavLink : public ANPC_Spline {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineNavLinkComponent* NavLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_JumpSplineData JSData;
    
public:
    ANPC_SplineNavLink(const FObjectInitializer& ObjectInitializer);
};

