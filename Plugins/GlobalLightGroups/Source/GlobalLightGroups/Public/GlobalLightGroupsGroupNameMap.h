#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightGroupsGroupNameMap.generated.h"

class UGlobalLightGroupsNamedGroupSchedules;
class UGlobalLightGroupsNamedLightComponentSchedules;

UCLASS(Blueprintable)
class UGlobalLightGroupsGroupNameMap : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> NameGroupMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> GroupNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsNamedGroupSchedules* GroupSchedules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightGroupsNamedLightComponentSchedules* LightComponentSchedules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ReferenceCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceGroup0OffGroup1On;
    
public:
    UGlobalLightGroupsGroupNameMap();
};

