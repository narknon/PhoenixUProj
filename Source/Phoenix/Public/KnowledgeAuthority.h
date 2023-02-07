#pragma once
#include "CoreMinimal.h"
#include "EKnowledgeLevel.h"
#include "KnowledgeAuthority.generated.h"

USTRUCT(BlueprintType)
struct FKnowledgeAuthority {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SubjectID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AuthorityID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EKnowledgeLevel Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SocialCapital;
    
    PHOENIX_API FKnowledgeAuthority();
};

