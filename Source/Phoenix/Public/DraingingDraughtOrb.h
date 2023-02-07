#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MunitionType_SubsonicSpell.h"
#include "DraingingDraughtOrb.generated.h"

UCLASS(Blueprintable)
class ADraingingDraughtOrb : public AMunitionType_SubsonicSpell {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_CurActiveRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_CurRotAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_AttackingDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_AttackingAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_AttackingSpeed;
    
    ADraingingDraughtOrb();
    UFUNCTION(BlueprintCallable)
    void Attack();
    
};

