#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CombatDOVCollection.generated.h"

class ADynamicObjectVolume;
class AEncounterVolume;

UCLASS(Blueprintable, EditInlineNew)
class UCombatDOVCollection : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<ADynamicObjectVolume*> IncludedDynamicObjectVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<AEncounterVolume*> IncludedEncounterVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<ADynamicObjectVolume*> ExcludedDynamicObjectVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<AEncounterVolume*> ExcludedEncounterVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<ADynamicObjectVolume*> ResolvedDOVCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<ADynamicObjectVolume*> UnrestrictedResolvedDOVCollection;
    
public:
    UCombatDOVCollection();
};

