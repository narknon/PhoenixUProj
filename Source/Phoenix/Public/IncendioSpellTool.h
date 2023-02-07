#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "Templates/SubclassOf.h"
#include "IncendioSpellTool.generated.h"

class AActor;
class AMunitionType_AOE_MultiFX;
class AMunitionType_Base;
class UMultiFX2_Base;

UCLASS(Blueprintable)
class AIncendioSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FlameFX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterDamageScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> AOEMunition;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMunitionType_AOE_MultiFX* CurrentAOE;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> AOEIgnoreList;
    
public:
    AIncendioSpellTool();
};

