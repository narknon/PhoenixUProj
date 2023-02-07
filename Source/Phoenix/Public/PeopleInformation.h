#pragma once
#include "CoreMinimal.h"
#include "EKnowledgeLevel.h"
#include "SocialCapitalStatusIDs.h"
#include "SocialSemanticIDs.h"
#include "PeopleInformation.generated.h"

USTRUCT(BlueprintType)
struct FPeopleInformation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PersonName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubtypeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> HouseID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialCapitalStatusIDs> SocialCap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EKnowledgeLevel CurrentKnowledgeLevel;
    
    PHOENIX_API FPeopleInformation();
};

